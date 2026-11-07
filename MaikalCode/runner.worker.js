// Python executes only inside this browser worker, never on a server.
let runtime;
self.onmessage = async ({data}) => {
  try {
    if (!runtime) {
      self.postMessage({status:'loading',message:'Loading the Python runtime. The first run needs an internet connection.'});
      const {loadPyodide} = await import('https://cdn.jsdelivr.net/pyodide/v314.0.7/full/pyodide.mjs');
      runtime = await loadPyodide();
      const response = await fetch(new URL('trace_runner.py', self.location.href));
      if (!response.ok) throw Error('Could not load the tracing harness. Serve the entire project folder.');
      await runtime.runPythonAsync(await response.text());
    }
    if (/SortedList|SortedDict|SortedSet/.test(data.code)) {
      self.postMessage({status:'loading',message:'Loading the sortedcontainers dependency…'});
      await runtime.loadPackage('sortedcontainers');
    }
    runtime.globals.set('mc_payload_json', JSON.stringify(data));
    const result = await runtime.runPythonAsync('run_payload(json.loads(mc_payload_json))');
    self.postMessage({status:'done',...JSON.parse(result)});
  } catch(error) {
    self.postMessage({status:'error',message:String(error)});
    // Allow retrying after a network or runtime setup failure.
    runtime = undefined;
  }
};

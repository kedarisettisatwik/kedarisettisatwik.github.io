# Content attribution

MaikalCode combines a custom learning interface and execution visualizer with attributed problem statements and solution collections. Attribution appears beside each solution in the interface.

- **LeetCode** — Original problem titles, links, statements, examples, topic tags, and hints from the local catalogue export. Each problem links to its original page on https://leetcode.com/. LeetCode is not affiliated with MaikalCode. These materials are not covered by the interface's license.
- **Doocs contributors, doocs/leetcode** — English descriptions where the local export lacked one, written approaches, and solution code. Source: https://github.com/doocs/leetcode. Licensed under **Creative Commons Attribution-ShareAlike 4.0 International**; full text is in `CONTENT-LICENSE.txt`. MaikalCode extracted the first nonempty Python/C++/Java solution per problem, reorganized the content, adjusted relative image URLs, and reformatted the prose for display. These adapted materials remain CC BY-SA 4.0. Each language retains its source link.
- **P.-Y. Chen (walkccc), walkccc/LeetCode** — Additional solutions where a language was missing from Doocs. Source: https://github.com/walkccc/LeetCode. Licensed under the **MIT License**, reproduced in `WALKCCC-LICENSE.txt`. Code is copied into language tabs without algorithmic modifications.
- **Pyodide contributors** — Browser Python execution runtime, loaded on demand from the official jsDelivr distribution. https://pyodide.org/. The Pyodide runtime uses the Mozilla Public License 2.0, and bundled components retain their respective licenses. Runtime files are fetched rather than bundled in this repository.

The catalogue snapshot is the previously downloaded 4,096-problem export. The filter excludes database/SQL questions identified by either the local metadata or source documents, four shell questions, and standalone Pandas/JavaScript language exercises. It retains coding topics such as concurrency and interactive algorithms, although their specialized judge environments may prevent generic execution.

`coverage.json` records the content-build timestamp, solution gaps, exclusion counts, and SHA-256 of the Doocs source archive. Downloaded source archives are not included in the distributable.

Retain this attribution and the content license files when publishing or adapting the project.

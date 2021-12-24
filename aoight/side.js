side_bar();

function side_bar() {
    var pages = ["task_page", "chat_page", "posts_page", "blogs_page", "history_page"];
    var notify = [1, 1, 0, 0, 1];
    for (var i = 0; i < pages.length; i++) {
        var pp = document.getElementById(pages[i]);
        var ll = pp.querySelector('label');
        if (notify[i] == 1) {
            pp.classList.add("noti");
            if (i == 1) {
                var ms = Math.floor(Math.random() * 28 + 2);
                ll.innerHTML = ms;
            } else {
                ll.innerHTML = "!";
            }
        } else {
            pp.classList.remove("noti");
            ll.innerHTML = "";
        }
    }
}

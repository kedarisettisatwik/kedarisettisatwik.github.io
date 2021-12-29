
function side_bar() {
    var pages = ["task_page", "chat_page", "posts_page", "blogs_page", "history_page"];
    var notify = [0,0, 0, 0, 0];
    var total = 0;
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
        total += notify[i];
    }
    if (total >= 1){
        document.querySelector('.bell').classList.add('active');
    }else{
        document.querySelector('.bell').classList.remove('active');
    }
}

function navigate_to(a){
    location.replace(a);
}

side_bar();
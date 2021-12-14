       var active_page = 0;

       var short = document.getElementById("short");

       function draw_s(){
           short.innerHTML = "";
           short.innerHTML += "<div class='cre'>Create ShortCut + </div>";
           var shorts = document.createElement('div');
           shorts.classList.add("shorts");
           shorts.innerHTML = "";
           
           var chats = ["Hani","Pranay"];
           var teams = ["EE207 Applications of EMI"];
           var blogs = ["Html Css","Js"];
           
           if (chats.length > 0){
               shorts.innerHTML += "<h2>Chats</h2>";
               for (var i = 0;i<chats.length;i++){
                   shorts.innerHTML += "<div class='to'><div class='pic'></div><p>"+chats[i]+"</p></div>";
               }
           }
           
           if (teams.length > 0){
               shorts.innerHTML += "<h2>Chats</h2>";
               for (var i = 0;i<teams.length;i++){
                   shorts.innerHTML += "<div class='to'><div class='pic'></div><p>"+teams[i]+"</p></div>";
               }
           }
           
           if (blogs.length > 0){
               shorts.innerHTML += "<h2>Blogs</h2>";
               for (var i = 0;i<blogs.length;i++){
                   shorts.innerHTML += "<div class='to'><div class='pic'></div><p>"+blogs[i]+"</p></div>";
               }
           }
           
           short.appendChild(shorts);
       }

       draw_s();

       function page_open(a) {
           location.replace(a);
       }

       function open_sub(a, b) {
           var sub = document.querySelector(a);
           sub.classList.toggle('active');
           var sub1 = document.querySelector(b);
           sub1.classList.toggle('active');
       }

       window.addEventListener('contextmenu', (e) => {
           e.preventDefault();
           var short = document.querySelector(".short");
           var xx = e.offsetX;
           var yy = e.offsetY;
           //           console.log(xx,yy);
           var wh = window.innerHeight;
           var ww = window.innerWidth;
           short.style.top = yy + "px";
           short.style.left = xx + "px";
           short.classList.add("active");

       });

       window.addEventListener("click", (e) => {
           var short = document.querySelector(".short");
           short.classList.remove("active");
       });

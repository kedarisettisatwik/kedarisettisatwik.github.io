       var active_page = 0;
       
       function page_open(a){
           location.replace(a);
       }
       
       function open_sub(a,b){
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
       
       window.addEventListener("click",(e) => {
           var short = document.querySelector(".short");
           short.classList.remove("active");
       });
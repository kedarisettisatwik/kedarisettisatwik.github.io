
        var today_hour = new Date().getHours();
        var today_min = new Date().getMinutes();
        var today_sec = new Date().getSeconds();
        
         var req_month = new Date().getMonth();
        var req_year = new Date().getFullYear(); 
        
        var sear_year = new Date().getFullYear(); 

        
        function draw(){
            
        var full_box = document.getElementById("calender");
        full_box.style.opacity = 0;
        
        setTimeout(function(){
         var today_date = new Date().getDate();
        var today_day = new Date().getDay();    
        
        var today_month = req_month;
        var today_year = req_year;
        var start = new Date(today_year,today_month,1);
        
        var top_bound = 0;
            
            if (today_month == 0 ||today_month == 2 ||today_month == 4 ||today_month == 6 ||today_month == 7 || today_month == 9 || today_month == 11){
                top_bound = 31;
            }else{
                if (today_month == 1){
                   if (req_year % 4 == 0){
                       top_bound = 29;
                   }else{
                       top_bound = 28;
                   }
                }else{
                    top_bound = 30;
                }
            }
            
            var str1= new Date(today_year,today_month,1);
            var month_li = ["Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"];
                
            var ele = document.getElementById("add_cal");
            ele.innerHTML = "";
            ele.innerHTML += "<li class='top flex'><i class='fas fa-chevron-left' onclick='change(-1)'></i>"+"<span id='month-cal' onclick='dis1()'>"+month_li[req_month]+"</span><span id='year-cal' onclick='dis1()'>"+today_year+"</span>" +"<i class='fas fa-chevron-right' onclick='change(1)'></i>" +"<i class='fas fa-redo-alt' onclick='inp1()'></i>"+"</li>";
            
            ele.innerHTML += "<li><ul class='days'><li>Sun</li><li>M</li><li>T</li><li>W</li><li>T</li><li>F</li><li>S</li></ul></li>";
         
            
            var count = 0;
            
            for (var i = 0;i<6;i++){
                var li1 = document.createElement("li");
                var ul1 = document.createElement("ul");
                ul1.classList.add("dates");
                ele.appendChild(li1);
                li1.appendChild(ul1);
                
                for (var j = 0;j<7;j++){
                    if (count > 0 && count < top_bound){
                         count += 1;
                        if (count == today_date){
                            ul1.innerHTML += "<li class='block active' onclick='pop1("+count+")'>"+count+"</li>";
                        }else{
                            ul1.innerHTML += "<li class='block' onclick='pop1("+count+")'>"+count+"</li>";
                        }
                    }else{
                        if (i == 0 && j == start.getDay()){
                            count += 1;
                             if (count == today_date){
                                 ul1.innerHTML += "<li class='block active' onclick='pop1("+count+")'>"+count+"</li>";
                             }else{
                                 ul1.innerHTML += "<li class='block' onclick='pop1("+count+")'>"+count+"</li>";
                             }
                        }else{
                            ul1.innerHTML += "<li>"+ " " +"</li>";
                        }
                    }
                }
            }
           full_box.style.opacity = 1;  
        },200); 
            
            year1();
            
        }
        
        draw();
        
        function year1(){
            var yy = document.getElementById("years");
            var mm = document.getElementById("months");
            
            yy.innerHTML = "<li class='flex list2'><i class='fas fa-arrow-left' onclick='past_p(-1)'></i><i class='fas fa-arrow-right' onclick='past_p(1)'></i><i class='far fa-times-circle' onclick='close1()'></i></li><li class='list2'><ul class='flex list1'><li onclick='year_com("+(sear_year - 4)+")'>"+(sear_year - 4)+"</li><li onclick='year_com("+(sear_year - 3)+")'>"+(sear_year - 3)+"</li><li onclick='year_com("+(sear_year - 2)+")'>"+(sear_year - 2)+"</li></ul></li><li class='list2'><ul class='flex list1'><li onclick='year_com("+(sear_year - 1)+")'>"+(sear_year - 1)+"</li><li onclick='year_com("+(sear_year - 0)+")'>"+(sear_year - 0)+"</li><li onclick='year_com("+(sear_year+1)+")'>"+(sear_year + 1)+"</li></ul></li><li class='list2'><ul class='flex list1'><li onclick='year_com("+(sear_year + 2)+")'>"+(sear_year + 2)+"</li><li onclick='year_com("+(sear_year + 3)+")'>"+(sear_year + 3)+"</li><li onclick='year_com("+(sear_year + 4)+")'>"+(sear_year + 4)+"</li></ul></li>";
    
            mm.innerHTML = "<li class='list12'><ul class='flex list11'><li onclick='month_com(0)'>Jan</li><li onclick='month_com(1)'>Feb</li><li onclick='month_com(2)'>Marc</li></ul></li> <li class='list12'><ul class='flex list11'><li onclick='month_com(3)'>Apr</li><li onclick='month_com(4)'>May</li><li onclick='month_com(5)'>June</li></ul></li> <li class='list12'><ul class='flex list11'><li onclick='month_com(6)'>July</li><li onclick='month_com(7)'>Aug</li><li onclick='month_com(8)'>Sept</li></ul></li><li class='list12'><ul class='flex list11'><li onclick='month_com(9)'>Oct</li><li onclick='month_com(10)'>Nov</li><li onclick='month_com(11)'>Dec</li></ul></li>";
        }
        
        function change(a){
            if (a == 1){
                if (req_month + a < 12){
                    req_month += 1;
                }else{
                    req_month = 0;
                    req_year += 1;
                }
            }else{
                 if (req_month + a > -1){
                    req_month -= 1;
                }else{
                    req_month = 11;
                    req_year -= 1;
                }
            }
            draw();
        }
        
        function mode1(){
            var ch = document.querySelector("input[type='checkbox']:checked");
            var short = document.getElementById("short");
           if (ch){
               
              // full mode
               short.style.opacity = 0;
               setTimeout(function(){
                   short.style.display = "none";
               },200);
               
           }else{
               // apppear
               short.style.display = "flex";
               setTimeout(function(){
                   short.style.opacity = 1;
               },200);
           }
        }
        
        function inp1(){
            req_month = new Date().getMonth();
            req_year = new Date().getFullYear();
            close1();
            year1();
            draw();
        }
        
        function pop1(a){
            var click_date = a;
            var click_month = document.getElementById("month-cal").innerHTML;
            var click_year = JSON.parse(document.getElementById("year-cal").innerHTML);
            var month_list = ["Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"];
            click_month = JSON.parse(month_list.indexOf(click_month));
            var list_blocks = document.querySelectorAll(".block");
            for(var i=0;i<list_blocks.length;i++){
                list_blocks[i].classList.remove("active1");
            }
            list_blocks[a-1].classList.add("active1");
            
            console.log(click_date + "/"+click_month+"/"+click_year);
        }
        
        function dis1(){
            var yy = document.getElementById("years");
            yy.style.display = "flex";
            setTimeout(function(){
                yy.style.opacity = 1;
            },300);
        }
        
        function close1(){
            var yy = document.getElementById("years");
             var mm = document.getElementById("months");
            yy.style.opacity = 0;
            mm.style.opacity = 0;   
            setTimeout(function(){
                yy.style.display = "none";
                mm.style.display = "none";
            },300);
            sear_year = req_year;
            year1();
        }
        function past_p(a){
            sear_year += (9 * a);
            year1();
        }
        function year_com(a){
            var yy = document.getElementById("years");
            sear_year = a;
            var mm = document.getElementById("months");
            mm.style.display = "flex";
            setTimeout(function(){
                mm.style.opacity = 1;
                 year1();
            },300);
        }
        function month_com(a){
            req_year = sear_year;
            req_month = a;
            draw();
            close1();
        }
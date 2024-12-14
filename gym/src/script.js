
function login(){
    var loginForm = document.getElementById("loginForm");
    console.log("log in");
}

var planType = 0;

function planChange(){
    var plan = document.getElementById("planSelect");
    planType = plan.value;
    changeAmount();
}

function changeAmount(){
    var amounts = [["1500","1000","2000","4000"],["4300","2800","5600","11,500"],["8700","5500","11,500","22,000"],["17,000","11,000","22,000","45,000"]];
    var amountEles = document.querySelectorAll(".amount");
    for(var i = 0;i < amountEles.length;i++){
        amountEles[i].innerHTML = amounts[planType][i];
    }
}

console.log("Rebuild Fitness");

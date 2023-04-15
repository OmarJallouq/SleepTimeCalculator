const time_picker_element = document.querySelector('.time-picker');

const hr_element = document.querySelector('.time-picker .hour .hr');
const min_element = document.querySelector('.time-picker .minute .min');

const hr_up = document.querySelector('.time-picker .hour .hr-up');
const hr_down = document.querySelector('.time-picker .hour .hr-down');

const min_up = document.querySelector('.time-picker .minute .min-up');
const min_down = document.querySelector('.time-picker .minute .min-down');

let d = new Date();
let hour = d.getHours();
let minute = d.getMinutes();
setTime();


// EVENT LISTENERS
hr_up.addEventListener('click', hour_up);
hr_down.addEventListener('click', hour_down);

min_up.addEventListener('click', minute_up);
min_down.addEventListener('click', minute_down);

hr_element.addEventListener('change', hour_change);
min_element.addEventListener('change', minute_change);


function hour_change (e) {
    if(e.target.value > 23){
        e.target.value = 23;
    }
    else if (e.target.value < 0){
        e.target.value = '00';
    }

    if(e.target.value == ""){
        e.target.value = formatTime(hour);
    }

    hour = e.target.value;
}

function minute_change (e) {
    if(e.target.value > 59){
        e.target.value = 59;
    }
    else if (e.target.value < 0){
        e.target.value = '00';
    }

    
    if(e.target.value == ""){
        e.target.value = formatTime(minute);
    }

    minute = e.target.value;
}

function hour_up () {
    hour++;

    if(hour > 23){
        hour=0;
    }
    setTime();
}

function hour_down () {
    hour--;

    if(hour < 0){
        hour=23;
    }
    setTime();
}


function minute_up () {
    minute++;

    if(minute > 59){
        minute=0;
        hour++;
        if(hour > 23){
            hour=0;
        }
    }
    setTime();
}

function minute_down () {
    minute--;

    if(minute < 0){
        minute=59;
        hour--;
        if(hour < 0){
            hour=23;
        }
    }
    setTime();
}


function setTime (){
    hr_element.value = formatTime(hour);
    min_element.value = formatTime(minute);
    time_picker_element.dataset.time = formatTime(hour) + ':' + formatTime(minute);
}

function formatTime (time) {
    if(time < 10){
        time = '0' + time;
    }
    return time;
}




function calcBedTime(){

    let tMinute = minute;
    let tHour = hour;
    let timings = ['','','','','',''];
    let list = document.getElementById("timeList");

    //time to sleep
    tMinute -= 15;

    //error checking, minutes and hours arent negative
    if(tMinute < 0){
        tHour--;
        tMinute += 60;
    }
    if(tHour < 0){
        tHour += 24;
    }

    //calculates sleeping times, (-1:30 iterations)
    for (let i = 0; i < 6; i++) {
        tHour--;
        tMinute-=30;

        if(tMinute < 0){
            tHour--;
            tMinute += 60;
        }
        if(tHour < 0){
            tHour += 24;
        }
        
        console.log(formatTime(tHour)+':'+formatTime(tMinute))

        timings[i]=formatTime(tHour) + ":" + formatTime(tMinute);

    }
    
    for (let i = 5; i>=0; i--){
        var li = document.createElement('li');
        li.innerText = timings[i];
        if(i>3){
            li.classList.add("time-list__item");
            li.classList.add("time-list__item_suggested");
        }
        else{
            li.classList.add("time-list__item");
        }
            list.appendChild(li);
    }
    var TIME = document.getElementById("time-view");
    TIME.style.display = "block";

    var OLD = document.getElementById("inputs");
    OLD.style.display = "none";

  
}

function calcWakeUp(){
    let f = new Date();
    let nHour = f.getHours();
    let nMinute = f.getMinutes();
    let list = document.getElementById("timeList");

    // it is currently __:__ correct? confirmation box DIDNT DO THIS
 
    //time to sleep 
    nMinute += 15;

    //error checking, not more than max values
    if(nMinute > 59){
        nHour++;
        nMinute -= 60;
    }

    if(nHour > 24){
        nHour -= 24;
    }

    //calculates waking up times (+1:30 iterations)
    for (let i = 0; i < 6; i++) {
        nHour++;
        nMinute+=30;

        if(nMinute > 59){
            nHour++;
            nMinute -= 60;
        }
        if(nHour >= 24){
            nHour -= 24;
        }
        
        console.log(formatTime(nHour)+':'+formatTime(nMinute))
        
        var li = document.createElement('li');
        li.innerText = formatTime(nHour) + ":" + formatTime(nMinute);
        if(i<2){
            li.classList.add("time-list__item");
            li.classList.add("time-list__item_suggested");
        }
        else{
            li.classList.add("time-list__item");
        }
            list.appendChild(li);
    }

    var TIME = document.getElementById("time-view");
    TIME.style.display = "block";

    var OLD = document.getElementById("inputs");
    OLD.style.display = "none";
}

function goBack() {
    var list = document.querySelector('ul');
    while(list.firstChild){
        list.removeChild(list.firstChild);
    }

    var TIME = document.getElementById("time-view");
    TIME.style.display = "none";

    var OLD = document.getElementById("inputs");
    OLD.style.display = "block";
}
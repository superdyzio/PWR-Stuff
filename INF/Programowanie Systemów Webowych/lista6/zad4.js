"use strict";

var textinput = document.getElementById('textinput');
var mouseEventsBtn = document.getElementById('mouseEventsBtn');

mouseEventsBtn.onclick = function (event) {
  textinput.onmousemove = function () {
    console.log("X: " + event.clientX + "   Y: " + event.clientY + "   x: " + event.screenX + "   y: " + event.screenY);
  };
  textinput.onmousedown = function () {
    console.log("Klik");
  };
  textinput.onmouseover = function () {
    console.log("Myszka tu jest");
  };
  textinput.onmouseout = function () {
    console.log("Myszka sobie poszła");
  };
};

function klawisze() {
  console.log("Alt: " + event.altKey + "   Ctrl: " + event.ctrlKey + "   Shift: " + event.shiftKey + "   Keycode: " + event.keyCode);
}

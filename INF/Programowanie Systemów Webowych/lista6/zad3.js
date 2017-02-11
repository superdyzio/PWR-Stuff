"use strict";

var redBackgroundBtn = document.getElementById('redBackgroundBtn');
var whiteBackgroundBtn = document.getElementById('whiteBackgroundBtn');
var zad3div = document.getElementById('zad3_div');
var fontstyle = document.getElementById('fontstyle');

redBackgroundBtn.onclick = function () {
  document.body.style.background = '#ff0000';
  zad3div.style.color = "white";
};

whiteBackgroundBtn.onclick = function () {
  document.body.style.background = "#ffffff";
  zad3div.style.color = "green";
};

fontstyle.onchange = function () {
  switch (fontstyle.value) {
    case 'bold': zad3div.style.fontWeight = "bold"; break;
    case 'italic': zad3div.style.fontStyle = "italic"; break;
    case 'normal': zad3div.style.fontWeight = "normal"; zad3div.style.fontStyle = "normal"; break;
  }
};

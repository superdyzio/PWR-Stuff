"use strict";

var form = document.getElementById('form');
var forminput1 = document.getElementById('forminput1');
var forminput2 = document.getElementById('forminput2');

forminput1.onfocus = function () {
  forminput2.value = "First input got focus!";
};

forminput1.onblur = function () {
  forminput2.value = "First input lost focus.";
};

form.onsubmit = function () {
  alert('Formularz wysłany');
};

form.onreset = function () {
  alert('Formularz wyczyszczony');
};

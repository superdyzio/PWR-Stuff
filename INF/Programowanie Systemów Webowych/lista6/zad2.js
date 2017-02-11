"use strict";

var countObjectsBtn = document.getElementById('countObjectsBtn');

countObjectsBtn.onclick = function () {
  console.log("Obrazy: " + document.images.length);
  console.log("Linki: " + document.links.length);
  console.log("Formularze: " + document.forms.length);
  console.log("<a>: " + document.anchors.length);

  console.log("Adres pierwszego linku: " + document.links.item(0).href);
  console.log("Adres linku o id 'a2': " + document.anchors.namedItem('a2'));
};

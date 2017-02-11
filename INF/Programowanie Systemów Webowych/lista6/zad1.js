"use strict";

var addElementBtn = document.getElementById('addElementBtn');
var clearListBtn = document.getElementById('clearListBtn');
var replaceElementBtn = document.getElementById('replaceElementBtn');
var insertElementBtn = document.getElementById('insertElementBtn');
var addButtonBtn = document.getElementById('addButtonBtn');
var list = document.getElementById('list');
var secondList = document.getElementById('secondList');

addElementBtn.onclick = function () {
  var li = document.createElement('LI');
  var text = document.createTextNode('list element');
  li.appendChild(text);
  list.appendChild(li);
};

clearListBtn.onclick = function () {
  while (list.childNodes.length > 0) {
    list.removeChild(list.childNodes[0]);
  }
};

replaceElementBtn.onclick = function () {
  var li = document.createElement('LI');
  var text = document.createTextNode('replacing element');
  li.appendChild(text);
  secondList.replaceChild(li, secondList.childNodes[3]);
};

insertElementBtn.onclick = function () {
  var li = document.createElement('LI');
  var text = document.createTextNode('new element');
  li.appendChild(text);
  secondList.insertBefore(li, secondList.childNodes[0]);
};

addButtonBtn.onclick = function () {
    var btn = document.createElement('BUTTON');
    var text = document.createTextNode('new button');
    btn.appendChild(text);
    addButtonBtn.parentNode.appendChild(btn);
};

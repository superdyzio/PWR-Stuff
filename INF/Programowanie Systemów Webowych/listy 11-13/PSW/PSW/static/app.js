function dropdownFunction() {
    document.getElementsByClassName("SubMenu").classList.toggle("show");
}
function addProducts() {
    if (event.altKey) {
        var nameProduct = window.prompt("Podaj nazwę produktu", "");
        var node = document.createElement('DIV');
        var h3 = document.createElement('H3');
        var href = document.createElement('a');
        var more = document.createElement('a');
        var desc = document.createElement('DIV');
        var p = document.createElement('P');
        var pdescv = window.prompt("Podaj krótki opis.", "");
        p.appendChild(document.createTextNode(pdescv));
        desc.className += 'short_description';
        node.className += 'product-block';
        href.href = createlink(nameProduct);
        href.title = nameProduct;
        href.appendChild(document.createTextNode(nameProduct));
        more.href = createlink(nameProduct);
        more.title = nameProduct;
        more.appendChild(document.createTextNode("Więcej"));
        h3.className += 'product-name';
        h3.appendChild(href);
        desc.appendChild(p);
        node.appendChild(h3);
        node.appendChild(desc);
        node.appendChild(more);
        document.getElementById('allproducts').appendChild(node);
    } else {
        alert("Wciśnij przycisk ALT!!");
    }
}
function createlink(nameProduct) {
    return window.location.href + nameProduct
        .toString()
        .trim()
        .toLowerCase()
        .replace(/\s+/g, "-")
        .replace(/[^\w\-]+/g, "")
        .replace(/\-\-+/g, "-")
        .replace(/^-+/, "")
        .replace(/-+$/, "") + '.html';
}
function changeBackgroundColor(selectTag) {
    var listValue = selectTag.options[selectTag.selectedIndex].text;
    document.getElementById("footer").style.background = listValue;
    document.getElementById("header").style.background = listValue;
}
function navItemChange(itemId) {
    $('#li1').removeClass('active');
    $('#li2').removeClass('active');
    $('#li3').removeClass('active');
    $('#li4').removeClass('active');
    $('#li3').addClass('active');
}


function contactLoad() {
    if (!isPostBack) {
        console.log('nie postback');
    } else {
        console.log('postback');
    }
}

function test() {
    console.log('test');
    return true;
}
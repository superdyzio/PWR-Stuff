<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="PSW.index" %>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
     <div id="main">
        <section class="page-description">
            <div class="container">
                <h1 class="page-title">O nas</h1>
                <p>Aliquam quis aliquam elit, eget imperdiet urna. Pellentesque quis rutrum orci, ac pretium metus.
                    Vivamus condimentum, lacus eu auctor dignissim, dui nisl viverra orci, non ultricies elit mi sed orci.</p>
                <p>Nullam tincidunt libero tortor, congue tincidunt velit dictum in.
                    Aliquam eu efficitur ex, nec elementum erat.
                    Nulla egestas pretium sapien, in consectetur dolor convallis at.
                    Lorem ipsum dolor sit amet, consectetur adipiscing elit. Proin id dignissim massa.</p>
                <p>Nulla urna ipsum, bibendum nec ullamcorper sed, euismod et velit.
                    Fusce aliquet rutrum mauris in feugiat.</p>
                <img src="./static/images/pizzeria.png" alt="Pizzeria" />
            </div>
        </section>
         <section class="section-products content">
            <div class="container">
         <div class="products" id="pizzas">
                    <div class="product-block">
                        <div class="product-image">
                            <a href="" title="Margarita">
                                <img src="./static/images/pizza.png" alt="Margarita" />
                            </a>
                        </div>
                        <h3 class="product-name">
                            <a href="" title="Margarita">
                                Margarita
                            </a>
                        </h3>
                        <div class="short_description">
                            <p> Aliquam quis aliquam elit, eget imperdiet urna. Pellentesque quis rutrum orci, ac pretium metus...</p>
                        </div>
                        <a onclick="dodaj()" title="Dodaj">Dodaj</a>
                    </div>
                    <div class="product-block">
                        <div class="product-image">
                            <a href="" title="Funghi">
                                <img src="./static/images/pizza.png" alt="Funghi" />
                            </a>
                        </div>
                        <h3 class="product-name">
                            <a href="" title="Funghi">
                                Funghi
                            </a>
                        </h3>
                        <div class="short_description">
                            <p> Aliquam quis aliquam elit, eget imperdiet urna. Pellentesque quis rutrum orci, ac pretium metus...</p>
                        </div>
                        <a onclick="dodaj()" title="Dodaj">Dodaj</a>
                    </div>
                    <div class="product-block">
                        <div class="product-image">
                            <a href="" title="Roma">
                                <img src="./static/images/pizza.png" alt="Roma" />
                            </a>
                        </div>
                        <h3 class="product-name">
                            <a href="" title="Roma">
                                Roma
                            </a>
                        </h3>
                        <div class="short_description">
                            <p> Aliquam quis aliquam elit, eget imperdiet urna. Pellentesque quis rutrum orci, ac pretium metus...</p>
                        </div>
                        <a onclick="dodaj()" title="Dodaj">Dodaj</a>
                    </div>
                    <div class="product-block">
                        <div class="product-image">
                            <a href="" title="Hawaii">
                                <img src="./static/images/pizza.png" alt="Hawaii"  />
                            </a>
                        </div>
                        <h3 class="product-name">
                            <a href="" title="Hawaii">
                                Hawaii
                            </a>
                        </h3>
                        <div class="short_description">
                            <p> Aliquam quis aliquam elit, eget imperdiet urna. Pellentesque quis rutrum orci, ac pretium metus...</p>
                        </div>
                        <a onclick="dodaj()" title="Dodaj">Dodaj</a>
                    </div>
                </div>
                <div class="button-block">
                    <a href="javascript:void(0)" onclick="addProducts()" id="addProduct" class="btn big-btn">Dodaj produkt. Trzymaj przycisk ALT !</a>
                </div>
                </div>
             </section>
    </div>
</asp:Content>

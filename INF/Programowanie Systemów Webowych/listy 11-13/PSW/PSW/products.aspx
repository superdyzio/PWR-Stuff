<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="products.aspx.cs" Inherits="PSW.products" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div id="main">
        <section class="section-products content">
            <div class="container">
                <div class="block-description">
                    <h2>Nasze produkty</h2>
                    <p>Lorem ipsum dolor sit amet, <strong>consectetur</strong> adipiscing elit. Proin id dignissim massa. Aliquam eu efficitur ex, nec elementum erat.</p>
                    <p>Nulla egestas pretium sapien, in consectetur dolor convallis at. Fusce <strong>aliquet rutrum mauris</strong> in feugiat.</p>
                </div>
                <form runat="server">
                    <asp:RadioButtonList ID="RadioButtonList1" runat="server" OnSelectedIndexChanged="productsVisibility" AutoPostBack="true">
                        <asp:ListItem>Pizza</asp:ListItem>
                        <asp:ListItem>Makarony</asp:ListItem>
                        <asp:ListItem>Sałatki</asp:ListItem>
                    </asp:RadioButtonList>
                    <div runat="server" id="pizzas">
                        <asp:CheckBox ID="Margerita" runat="server" Text="Margerita"/><br />
                        <asp:CheckBox ID="Roma" runat="server" Text="Roma"/><br />
                        <asp:CheckBox ID="Funghi" runat="server" Text="Funghi"/><br />
                        <asp:CheckBox ID="Hawaii" runat="server" Text="Hawaii"/>
                    </div>
                    <div runat="server" id="pastas">
                        <asp:CheckBox ID="Carbonara" runat="server" Text="Carbonara"/><br />
                        <asp:CheckBox ID="Bolognese" runat="server" Text="Bolognese"/><br />
                        <asp:CheckBox ID="Napoli" runat="server" Text="Napoli"/>
                    </div>
                    <div runat="server" id="salad">
                        <asp:CheckBox ID="Grecka" runat="server" Text="Grecka"/><br />
                        <asp:CheckBox ID="Cezar" runat="server" Text="Cezar"/><br />
                        <asp:CheckBox ID="Wiosenna" runat="server" Text="Wiosenna"/><br />
                        <asp:CheckBox ID="Caprese" runat="server" Text="Caprese"/>
                    </div>
                    <asp:Button ID="submit" runat="server" Text="Dodaj do koszyka" OnClick="koszyk" />
                    <asp:Button ID="clear" runat="server" Text="Wyczyść koszyk " OnClick="czysc" />
                    <asp:Label ID="countLabel"
                               Text="Produktów w koszyku: "
                               AssociatedControlID="countValue"
                               runat="server">
                        <asp:TextBox ID="countValue" runat="server" />
                    </asp:Label>
                </form>
            </div>
        </section>
    </div>
</asp:Content>

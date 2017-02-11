<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="basket.aspx.cs" Inherits="PSW.basket" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
     <form runat="server">
        <asp:RadioButtonList ID="DostawaRadioButton" runat="server" AutoPostBack="true">
            <asp:ListItem>Dowóz</asp:ListItem>
            <asp:ListItem>Odbiór osobisty</asp:ListItem>
            <asp:ListItem>Na miejscu</asp:ListItem>
        </asp:RadioButtonList>
        <asp:Label ID="priceLabel"
                Text="Łączna cena: "
                AssociatedControlID="priceValue"
                runat="server">
        <asp:TextBox ID="priceValue" runat="server" ReadOnly="true" />
        </asp:Label>
    </form>
    <button ID="confirmOrder" onclick="confirm()">Potwierdź</button>
    <script type="text/javascript">
        function potwierdz() {
            console.log('hehe');
            if ($('#confirmOrder').text == '0') {
                alert("Koszyk jest pusty!");
                console.log('oki');
            } else {
                alert("Zamówienie potwierdzone!");
                console.log('nieoki');
            }
        }
    </script>
</asp:Content>

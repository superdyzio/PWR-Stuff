<%@ Page Title="" Language="C#" MasterPageFile="~/Site1.Master" AutoEventWireup="true" CodeBehind="contact.aspx.cs" Inherits="PSW.contact" %>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <div id="main" onload="contactLoad()">
        <section class="page-description">
            <div class="container">
                <h1 class="page-title">Kontakt</h1>
                <p>Wypełnij poniższy formularz jeśli chcesz zadać nam pytanie lub przedstawić nam oferte biznesową</p>
            </div>
        </section>
        <div class="content">
            <div class="container">
                <div class="contact-blocks">
                    <div class="contact-block">
                        Wybrzeże Stanisława Wyspiańskiego 27, 50-370 Wrocław
                    </div>
                    <div class="contact-block">
                        Numer telefonu: <a href="tel:+48000000000" title="Zadzwoń do nas" style="display:inline-block;">+48 000 000 000</a>
                        <br />
                        Adres e-mail:
                        <a href="mailto:test@pizzeria.com" title="Napisz do nas" style="display:inline-block;">
                            test@pizzeria.com
                        </a>
                    </div>
                </div>


                <p style="text-align:center;font-weight:bold;">
                    <asp:Label ID="FormData1" Visible="false" runat="server"></asp:Label>
                    <br />
                    <asp:Label ID="FormData2" Visible="false" runat="server"></asp:Label>
                    <br />
                    <asp:Label ID="FormData3" Visible="false" runat="server"></asp:Label>
                    <br />
                    <asp:Label ID="FormData4" Visible="false" runat="server"></asp:Label>
                    <br />
                    <asp:Label ID="FormData5" Visible="false" runat="server"></asp:Label>
                    <br />
                    <asp:Label ID="FormData6" Visible="false" runat="server"></asp:Label>
                </p>
                <form class="contact-form" runat="server" name="contact-form" autocomplete="on" onsubmit="return test();">
                    <ul>
                        <li>
                            <asp:Label ID="lName"  runat="server" AssociatedControlID="name"><span style="color:red">*</span> Imię</asp:Label>
                            <asp:TextBox runat="server" ID="name"></asp:TextBox>
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="rfdName" runat="server" ControlToValidate="name" rrorMessage="Imię jest wymagane." Display="Dynamic" />
                                <asp:RegularExpressionValidator runat="server" ControlToValidate="name" ValidationExpression="^[a-zA-ZąćęłńóśźżĄĘŁŃÓŚŹŻ']{1,20}$" ErrorMessage="Imię nie może zawierać takich znaków!" Display="Dynamic"></asp:RegularExpressionValidator>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lSurname" runat="server" AssociatedControlID="surname">Nazwisko</asp:Label>
                            <asp:TextBox runat="server" ID="surname"></asp:TextBox>
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="rfdSurname" runat="server" ControlToValidate="surname" rrorMessage="Nazwisko jest wymagane." Display="Dynamic" />
					            <asp:RegularExpressionValidator runat="server" ControlToValidate="surname" ValidationExpression="^[a-zA-ZąćęłńóśźżĄĘŁŃÓŚŹŻ']{1,20}$" ErrorMessage="Nazwisko nie może zawierać takich znaków!" Display="Dynamic"></asp:RegularExpressionValidator>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lEmail" runat="server" AssociatedControlID="email"><span style="color:red">*</span> Adres e-mail <br /><span style="font-size:12px">np. test@hurtownia-pieczywa.com</span></asp:Label>
                            <asp:TextBox ID="email" runat="server" TextMode="Email"></asp:TextBox>
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="rfdEmail" runat="server" ControlToValidate="email" ErrorMessage="To pole jest wymagane" Display="Dynamic"/>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lTel" runat="server" AssociatedControlID="tel">Numer telefonu<br /><span style="font-size:12px">np. 500500500</span></asp:Label>
                            <asp:TextBox runat="server" ID="tel"></asp:TextBox>
                            <p class="error-field">
                                <asp:RegularExpressionValidator ID="RegularExpressionValidator2" 
                                    runat="server" ErrorMessage="Wprowadź prawidłowy numer telefonu" 
                                    ControlToValidate="tel" 
                                    ValidationExpression= "\d{3}\d{3}\d{3}"></asp:RegularExpressionValidator>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lAge" runat="server" AssociatedControlID="age"><span style="color:red">*</span> Wiek</asp:Label>
                            <asp:TextBox runat="server" ID="age"></asp:TextBox>
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="rfdAge" runat="server" ControlToValidate="age" CssClass="field-validation-error" ErrorMessage="Wiek jest wymagany." Display="Dynamic" />
                                <asp:RangeValidator ID="NumberRangeValidator" runat="server" ErrorMessage="Zły wiek! Nie mieści się w przedziale [23;70]" MinimumValue="23" MaximumValue="70" Type="Integer" ControlToValidate="age" Display="Dynamic"></asp:RangeValidator>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lCompareValidator" runat="server" AssociatedControlID="comp"><span style="color:red">*</span> Podaj liczbę większą niż 10:</asp:Label>
                            <asp:TextBox id="comp" runat="server" />
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="rfdComp" runat="server" ControlToValidate="comp" ErrorMessage="To pole jest wymagane" Display="Dynamic"/>
                                <asp:CompareValidator ID="rfdCompValidator" runat="server" ControlToValidate="comp" ValueToCompare="10" Operator="GreaterThan" ErrorMessage="Musi być większe od 10!" Display="Dynamic"></asp:CompareValidator>
                            </p>
                        </li>
                        <li>
                            <asp:Label ID="lMessage" runat="server" AssociatedControlID="message"><span style="color:red">*</span> Treść wiadomości</asp:Label>
                            <asp:TextBox id="message" TextMode="multiline" runat="server" />
                            <p class="error-field">
                                <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="message" ErrorMessage="To pole jest wymagane" Display="Dynamic"/>
                            </p>
                        </li>
                        <li class="buttons">
                            <asp:Button ID="submit" runat="server" Text="Wyślij wiadomość" />
                        </li>
                    </ul>
                    <div class="clear"></div>
                </form>
            </div>
        </div>
    </div>
</asp:Content>

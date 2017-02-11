using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace PSW
{
    public partial class products : System.Web.UI.Page
    {
        public static List<string> lista = new List<string>();

        protected void Page_Load(object sender, EventArgs e)
        {
            pizzas.Visible = false;
            pastas.Visible = false;
            salad.Visible = false;

            countValue.Text = "0";
        }

        public void productsVisibility(object sender, EventArgs e)
        {
            pizzas.Visible = RadioButtonList1.SelectedItem.Text.Equals("Pizza");
            pastas.Visible = RadioButtonList1.SelectedItem.Text.Equals("Makarony");
            salad.Visible = RadioButtonList1.SelectedItem.Text.Equals("Sałatki");
        }

        public void koszyk(object sender, EventArgs e)
        {
            if (Margerita.Checked && Array.IndexOf(lista.ToArray(), "Margerita") == -1)
            {
                lista.Add("Margerita");
            }
            if (Roma.Checked && Array.IndexOf(lista.ToArray(), "Roma") == -1)
            {
                lista.Add("Roma");
            }
            if (Funghi.Checked && Array.IndexOf(lista.ToArray(), "Funghi") == -1)
            {
                lista.Add("Funghi");
            }
            if (Hawaii.Checked && Array.IndexOf(lista.ToArray(), "Hawaii") == -1)
            {
                lista.Add("Hawaii");
            }
            if (Carbonara.Checked && Array.IndexOf(lista.ToArray(), "Carbonara") == -1)
            {
                lista.Add("Carbonara");
            }
            if (Bolognese.Checked && Array.IndexOf(lista.ToArray(), "Bolognese") == -1)
            {
                lista.Add("Bolognese");
            }
            if (Napoli.Checked && Array.IndexOf(lista.ToArray(), "Napoli") == -1)
            {
                lista.Add("Napoli");
            }
            if (Grecka.Checked && Array.IndexOf(lista.ToArray(), "Grecka") == -1)
            {
                lista.Add("Grecka");
            }
            if (Cezar.Checked && Array.IndexOf(lista.ToArray(), "Cezar") == -1)
            {
                lista.Add("Cezar");
            }
            if (Wiosenna.Checked && Array.IndexOf(lista.ToArray(), "Wiosenna") == -1)
            {
                lista.Add("Wiosenna");
            }
            if (Caprese.Checked && Array.IndexOf(lista.ToArray(), "Caprese") == -1)
            {
                lista.Add("Caprese");
            }

            countValue.Text = lista.Count.ToString();
        }

        public void czysc(object sender, EventArgs e)
        {
            lista.Clear();
            Margerita.Checked = false;
            Roma.Checked = false;
            Funghi.Checked = false;
            Hawaii.Checked = false;
            Carbonara.Checked = false;
            Bolognese.Checked = false;
            Napoli.Checked = false;
            Grecka.Checked = false;
            Cezar.Checked = false;
            Wiosenna.Checked = false;
            Caprese.Checked = false;

            countValue.Text = lista.Count.ToString();
        }
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace PSW
{
    public partial class basket : System.Web.UI.Page
    {
        List<String> lista = products.lista;

        public int listCount
        {
            get
            {
                return lista.Count;
            }
        }

        protected void Page_Load(object sender, EventArgs e)
        {
            priceValue.Text = calculatePrice();
        }

        private string calculatePrice()
        {
            int total = 0;
            string[] pizzas = { "Margerita", "Roma", "Funghi", "Hawaii" };
            string[] pastas = { "Carbonara", "Bolognese", "Napoli" };
            string[] salad = { "Grecka", "Cezar", "Wiosenna", "Caprese" };
            for (int i = 0; i < lista.Count; i++)
            {
                if (Array.IndexOf(pizzas, lista.ElementAt(i)) != -1)
                {
                    total += 20;
                } else if (Array.IndexOf(pastas, lista.ElementAt(i)) != -1)
                {
                    total += 15;
                } else if (Array.IndexOf(salad, lista.ElementAt(i)) != -1)
                {
                    total += 10;
                }
            }

            return total.ToString();
        }
    }
}
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DawidPerdekZad1
{
    public partial class FormClassicCalculator : Form
    {
        double result;          // akumulator przechowujący obecny rezultat
        double lastnumber;      // zmienna przechowująca drugi element działania
        double memory;          // pamięć sumująco-różnicująca kalkulatora
        string operation;       // zmienna przechowująca informację o operacji do wykonania
        bool operation_done;    // zmienna przechowująca informację o właśnie wykonanym działaniu

        public FormClassicCalculator()
        {
            InitializeComponent();
            result = lastnumber = memory = 0;
            operation = "";
            operation_done = false;
            textBoxEquationClassic.Text = "0";
        }

        private void numberDelete(object sender, EventArgs e)
        {
            if (operation_done)
            {
                operation_done = false;
                textBoxEquationClassic.Text = "0";
                operation = "";
                result = lastnumber = 0;
            }
            if (operation != "" && textBoxEquationClassic.Text == "0")
            {
                operation = "";
            }
            if (textBoxEquationClassic.Text.Length > 0 && textBoxEquationClassic.Text != "0")
                textBoxEquationClassic.Text = textBoxEquationClassic.Text.Substring(0, textBoxEquationClassic.Text.Length - 1);
            if (textBoxEquationClassic.Text.Length == 0)
                textBoxEquationClassic.Text = "0";
        }

        private void operationOnClick(object sender, EventArgs e)
        {
            lastnumber = double.Parse(textBoxEquationClassic.Text);
            textBoxEquationClassic.Text = "0";
            if (sender == buttonAdd)
                operation = "add";
            else if (sender == buttonSubtract)
                operation = "subtract";
            else if (sender == buttonMultiple)
                operation = "multiple";
            else if (sender == buttonDivide)
                operation = "divide";
        }

        private void calculateOnClick(object sender, EventArgs e)
        {
            if (operation != "")
            {
                bool ok = true;
                if (operation == "add")
                    result = lastnumber + double.Parse(textBoxEquationClassic.Text);
                else if (operation == "subtract")
                    result = lastnumber - double.Parse(textBoxEquationClassic.Text);
                else if (operation == "multiple")
                    result = lastnumber * double.Parse(textBoxEquationClassic.Text);
                else if (operation == "divide")
                {
                    double pom = double.Parse(textBoxEquationClassic.Text);
                    if (pom != 0)
                        result = lastnumber / pom;
                    else
                    {
                        MessageBox.Show("Nie można dzielić przez zero!");
                        ok = false;
                    }
                }
                if (ok)
                {
                    MessageBox.Show("Wynik: " + result.ToString("F2"));
                    result = Math.Round(result, 4);
                    textBoxEquationClassic.Text = result.ToString();
                    operation_done = true;
                }
                else
                {
                    textBoxEquationClassic.Text = "0";
                    result = lastnumber = 0;
                }
                operation = "";
            }
        }

        private void memoryOnClick(object sender, EventArgs e)
        {
            if (sender == buttonMemoryAdd)
                memory += double.Parse(textBoxEquationClassic.Text);
            else if (sender == buttonMemorySubtract)
                memory -= double.Parse(textBoxEquationClassic.Text);
            else if (sender == buttonMemoryShow)
                textBoxEquationClassic.Text = memory.ToString();
            else if (sender == buttonMemoryClear)
                memory = 0;
        }

        private void numberOnClick(object sender, EventArgs e)
        {
            if (textBoxEquationClassic.Text == "0")
                if (sender != buttonComma)
                    textBoxEquationClassic.Text = "";
            if (sender == buttonOne)
                textBoxEquationClassic.Text += '1';
            else if (sender == buttonTwo)
                textBoxEquationClassic.Text += '2';
            else if (sender == buttonThree)
                textBoxEquationClassic.Text += '3';
            else if (sender == buttonFour)
                textBoxEquationClassic.Text += '4';
            else if (sender == buttonFive)
                textBoxEquationClassic.Text += '5';
            else if (sender == buttonSix)
                textBoxEquationClassic.Text += '6';
            else if (sender == buttonSeven)
                textBoxEquationClassic.Text += '7';
            else if (sender == buttonEight)
                textBoxEquationClassic.Text += '8';
            else if (sender == buttonNine)
                textBoxEquationClassic.Text += '9';
            else if (sender == buttonZero)
                textBoxEquationClassic.Text += '0';
            else if (sender == buttonComma)
            {
                if (textBoxEquationClassic.Text.Contains(','))
                    MessageBox.Show("W liczbie już jest przecinek!");
                else
                    textBoxEquationClassic.Text += ',';
            }
        }
    }
}

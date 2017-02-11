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
    public partial class FormAdvancedCalculator : Form
    {
        Stack<char> operators;  // stos operatorów do wyliczania 'x'
        Stack<int> operands;    // stos wartości do wyliczania 'x'
        bool error;             // zmienna wskazująca błąd w trakcie wylicznia 'x'

        public FormAdvancedCalculator()
        {
            InitializeComponent();
            operators = new Stack<char>();
            operands = new Stack<int>();
            error = false;
        }

        private void buttonCalculateXParse_Click(object sender, EventArgs e)
        {
            bool correct = true;
            bool tooLessElements = false;
            double result = 0;
            string equation = textBoxEquationAdvanced.Text;
            string[] sides = equation.Split('=');
            for (int i = 0; i < sides.Length; i++)
                sides[i] = sides[i].Replace(" ", String.Empty);
            if (sides.Length == 2 && sides[0] == "x" && sides[1] != "")
            {
                string[] elements = sides[1].Split('+', '-', '*', '/');
                int numberOfOperations = elements.Length - 1;
                if (elements[0] == "")
                {
                    tooLessElements = true;
                    result = double.Parse(elements[1]);
                    if (sides[1].IndexOf('-') != -1)
                        result *= -1;
                }
                if (elements.Length < 2)
                {
                    tooLessElements = true;
                    result = double.Parse(elements[0]);
                }
                for (int i = 0; i < numberOfOperations && !tooLessElements; i++)
                {
                    int indexAdd = sides[1].IndexOf('+');
                    int indexSubtract = sides[1].IndexOf('-');
                    int indexMultiple = sides[1].IndexOf('*');
                    int indexDivide = sides[1].IndexOf('/');
                    double numberA = double.Parse(elements[i]);
                    double numberB = double.Parse(elements[i + 1]);
                    if (indexAdd == 0)
                    {
                        sides[1] = sides[1].Substring(indexAdd + 1);
                        indexAdd = sides[1].IndexOf('+');
                    }
                    if (indexSubtract == 0)
                    {
                        sides[1] = sides[1].Substring(indexSubtract + 1);
                        indexSubtract = sides[1].IndexOf('+');
                        numberA = -numberA;
                    }
                    if ((indexAdd >= 0 && indexAdd < indexSubtract) || (indexAdd != -1 && indexSubtract == -1))
                    {
                        if (indexAdd != -1)
                        {
                            result = numberB + numberA;
                            elements[i] = elements[i + 1] = result.ToString();
                            sides[1] = sides[1].Substring(indexAdd + 1);
                        }
                    }
                    else if (indexSubtract != -1)
                    {
                        result = numberA - numberB;
                        elements[i] = elements[i + 1] = result.ToString();
                        sides[1] = sides[1].Substring(indexSubtract + 1);
                    }
                }
            }
            else
                correct = false;
            if (!correct)
            {
                MessageBox.Show("Wprowadzono błędne równanie.");
                textBoxResult.Text = "0";
            }
            else
            {
                MessageBox.Show("Wynik: " + result);
                textBoxResult.Text = result.ToString();
            }
        }

        private void buttonCalculateY_Click(object sender, EventArgs e)
        {
            chartY.Series["Data"].Points.Clear();
            double left, right;
            bool correct = true;
            left = double.Parse(textBoxLeft.Text);
            right = double.Parse(textBoxRight.Text);
            if (left >= right)
                correct = false;
            string equation = textBoxEquationAdvanced.Text;
            string[] sides = equation.Split('=');
            for (int i = 0; i < sides.Length; i++)
                sides[i] = sides[i].Replace(" ", String.Empty);
            if (sides[0] == "y" && correct)
            {
                string[] elements = sides[1].Split('+', '-');
                int degree = elements.Length - 1;
                double[] coefficients = new double[degree + 1];
                for (int i = 0; i < degree; i++)
                    coefficients[i] = double.Parse(elements[i].Split('x')[0]);
                coefficients[degree] = double.Parse(elements[degree]);
                for (double i = left; i <= right; i += 0.01)
                {
                    double value = coefficients[0] * Math.Pow(i, degree);
                    string sidesCopy = sides[1];
                    for (int j = 1; j <= degree; j++)
                    {
                        int indexAdd = sidesCopy.IndexOf('+');
                        int indexSubtract = sidesCopy.IndexOf('-');
                        if (indexAdd != -1 && indexAdd < indexSubtract)
                        {
                            value += coefficients[j] * Math.Pow(i, degree - j);
                            sidesCopy = sidesCopy.Substring(indexAdd + 1);
                        }
                        else if (indexSubtract != -1)
                        {
                            value -= coefficients[j] * Math.Pow(i, degree - j);
                            sidesCopy = sidesCopy.Substring(indexSubtract + 1);
                        }
                    }
                    chartY.Series["Data"].Points.AddXY(i, value);
                }
            }
            else
                MessageBox.Show("Wprowadzono błędne równanie i/lub przedział.");
        }

        /// <summary>
        /// Funkcja napisana na podstawie kodu z GitHuba z repozytorium blog-codes użytkownika kartikkukreja.
        /// https://github.com/kartikkukreja/blog-codes/blob/master/src/Executing%20infix%20arithmetic%20expressions.cpp
        /// </summary>
        /// <param name="op1">pierwszy z porównywanych operatorów</param>
        /// <param name="op2">drugi z porównywanych operatorów</param>
        /// <returns>Zwraca true jeżeli drugi operator ma mniejszy lub równy priortet w porównaniu
        /// z operatorem pierwszym, w przeciwnym wypadku zwraca false.</returns>
        bool hasLowerPriority(char op1, char op2)
        {
            switch (op1)
            {
                case '(': return false;
                case '-': return op2 == '+';
                case '+': return op2 == '-' || op2 == '+';
                case '*': return op2 != '/';
                case '/': return true;
                default: error = true; return false;
            }
        }

        /// <summary>
        /// Funkcja napisana na podstawie kodu z GitHuba z repozytorium blog-codes użytkownika kartikkukreja.
        /// https://github.com/kartikkukreja/blog-codes/blob/master/src/Executing%20infix%20arithmetic%20expressions.cpp
        /// </summary>
        /// <param name="op">Operator działania, które ma zostać wykonane.</param>
        void operation(char op)
        {
            if (operands.Count < 2)
            {
                error = true; return;
            }
            int op2 = operands.Pop();
            int op1 = operands.Pop();
            switch (op)
            {
                case '+': operands.Push(op1 + op2); break;
                case '-': operands.Push(op1 - op2); break;
                case '*': operands.Push(op1 * op2); break;
                case '/': operands.Push(op1 / op2); break;
                default: error = true; return;
            }
        }

        /// <summary>
        /// Funkcja napisana na podstawie kodu z GitHuba z repozytorium blog-codes użytkownika kartikkukreja.
        /// https://github.com/kartikkukreja/blog-codes/blob/master/src/Executing%20infix%20arithmetic%20expressions.cpp
        /// </summary>
        /// <param name="sender">nazwa obiektu wywołującego zdarzenie</param>
        /// <param name="e"></param>
        private void buttonCalculateXStack_Click(object sender, EventArgs e)
        {
            int number = 0;
            string[] sides = textBoxEquationAdvanced.Text.Split('=');
            string expression = sides[1];
            sides[0] = sides[0].Replace(" ", String.Empty);
            if (sides.Length == 2 && sides[0].Equals("x") && !sides[1].Equals(""))
                expression += " )";
            operators.Push('(');
            string[] elements = expression.Split(' ');
            for (int i = 1; i < elements.Length && !error; i++)
            {
                if (int.TryParse(elements[i], out number))
                    operands.Push(number);
                else
                    switch (elements[i])
                    {
                        case "(": operators.Push('('); break;
                        case ")":
                            while (operators.Any() && !error && operators.Peek() != '(')
                            {
                                operation(operators.Peek());
                                operators.Pop();
                            }
                            if (operators.Any())
                                operators.Pop();
                            else
                                error = true;
                            break;
                        default:
                            while (operators.Any() && !error && hasLowerPriority(operators.Peek(), elements[i].ToCharArray()[0]))
                            {
                                operation(operators.Peek());
                                operators.Pop();
                            }
                            operators.Push(elements[i].ToCharArray()[0]);
                            break;
                    }
            }
            if (error || operators.Any() || operands.Count != 1)
            {
                MessageBox.Show("Wprowadzono błędne równanie.");
                while (operands.Any())
                    operands.Pop();
                while (operators.Any())
                    operators.Pop();
            }
            else
            {
                double result = operands.Pop();
                MessageBox.Show("Wynik: " + result.ToString());
                textBoxResult.Text = result.ToString();
            }
        }
    }
}
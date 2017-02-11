using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;

namespace Opinie
{
    public partial class opinie : PhoneApplicationPage
    {
        App myApp = Application.Current as App;
        double max, min, imax, imin;
        double[] tabela;

        public opinie()
        {
            InitializeComponent();
        }

        public void slupki()
        {
            tabela = new double[10];
            max = 0; min = 11;
            if (myApp.panie)
            {
                for (int i = 0; i < myApp.opiniePan.Count; i++)
                    tabela[myApp.opiniePan.ElementAt(i) - 1]++;
            }
            else
            {
                for (int i = 0; i < myApp.opiniePanow.Count; i++)
                    tabela[myApp.opiniePanow.ElementAt(i) - 1]++;
            }
            for (int i = 0; i < 10; i++)
            {
                if (tabela[i] > max)
                {
                    max = tabela[i];
                    imax = i;
                }
                if (tabela[i] < min)
                {
                    min = tabela[i];
                    imin = i;
                }
            }

            jeden.Height = tabela[0] / max * 250;
            dwa.Height = tabela[1] / max * 250;
            trzy.Height = tabela[2] / max * 250;
            cztery.Height = tabela[3] / max * 250;
            piec.Height = tabela[4] / max * 250;
            szesc.Height = tabela[5] / max * 250;
            siedem.Height = tabela[6] / max * 250;
            osiem.Height = tabela[7] / max * 250;
            dziewiec.Height = tabela[8] / max * 250;
            dziesiec.Height = tabela[9] / max * 250;

            Canvas.SetTop(jeden, 250 - jeden.Height);
            Canvas.SetTop(dwa, 250 - dwa.Height);
            Canvas.SetTop(trzy, 250 - trzy.Height);
            Canvas.SetTop(cztery, 250 - cztery.Height);
            Canvas.SetTop(piec, 250 - piec.Height);
            Canvas.SetTop(szesc, 250 - szesc.Height);
            Canvas.SetTop(siedem, 250 - siedem.Height);
            Canvas.SetTop(osiem, 250 - osiem.Height);
            Canvas.SetTop(dziewiec, 250 - dziewiec.Height);
            Canvas.SetTop(dziesiec, 250 - dziesiec.Height);

            //SolidColorBrush mySolidColorBrush = new SolidColorBrush();
            //mySolidColorBrush.Color = Color.FromArgb(255, 255, 255, 0);

            //System.Windows.Shapes.Rectangle rect = (System.Windows.Shapes.Rectangle)sender;
            //rect.Fill = mySolidColorBrush;

            //switch (imax)
            //{
            //    case 0: jeden.Style.
            //}
        }

        private void PhoneApplicationPage_Loaded(object sender, RoutedEventArgs e)
        {
            slupki();
            if (myApp.panie)
                naglowek.Text = "Opinie Pań";
            else
                naglowek.Text = "Opinie Panów";
        }
    }
}
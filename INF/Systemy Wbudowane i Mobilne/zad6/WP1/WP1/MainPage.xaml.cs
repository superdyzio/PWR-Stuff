using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using WP1.Resources;
using System.Windows.Media;

namespace WP1
{
    public partial class MainPage : PhoneApplicationPage
    {
        Kolory k;
        // Constructor
        public MainPage()
        {
            InitializeComponent();
            k = new Kolory();
            // Sample code to localize the ApplicationBar
            //BuildLocalizedApplicationBar();
        }

        private void sliderR_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            sliderV.Value = k.calculateV(sliderR.Value, sliderG.Value, sliderB.Value);
            sliderS.Value = k.calculateS(sliderR.Value, sliderG.Value, sliderB.Value);
            ustawKolor(sliderR.Value, sliderG.Value, sliderB.Value);
        }

        private void sliderG_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            sliderV.Value = k.calculateV(sliderR.Value, sliderG.Value, sliderB.Value);
            sliderS.Value = k.calculateS(sliderR.Value, sliderG.Value, sliderB.Value);
            ustawKolor(sliderR.Value, sliderG.Value, sliderB.Value);
        }

        private void sliderB_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            sliderV.Value = k.calculateV(sliderR.Value, sliderG.Value, sliderB.Value);
            sliderS.Value = k.calculateS(sliderR.Value, sliderG.Value, sliderB.Value);
            ustawKolor(sliderR.Value, sliderG.Value, sliderB.Value);
        }

        
        public void ustawKolor(double r, double g, double b)
        {
            var brush = new SolidColorBrush(Color.FromArgb(255, (byte)r, (byte)g, (byte)b));
            canvas.Background = brush;
        }

        // Sample code for building a localized ApplicationBar
        //private void BuildLocalizedApplicationBar()
        //{
        //    // Set the page's ApplicationBar to a new instance of ApplicationBar.
        //    ApplicationBar = new ApplicationBar();

        //    // Create a new button and set the text value to the localized string from AppResources.
        //    ApplicationBarIconButton appBarButton = new ApplicationBarIconButton(new Uri("/Assets/AppBar/appbar.add.rest.png", UriKind.Relative));
        //    appBarButton.Text = AppResources.AppBarButtonText;
        //    ApplicationBar.Buttons.Add(appBarButton);

        //    // Create a new menu item with the localized string from AppResources.
        //    ApplicationBarMenuItem appBarMenuItem = new ApplicationBarMenuItem(AppResources.AppBarMenuItemText);
        //    ApplicationBar.MenuItems.Add(appBarMenuItem);
        //}
    }
}
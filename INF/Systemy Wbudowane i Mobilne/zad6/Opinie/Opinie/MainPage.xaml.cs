using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Opinie.Resources;

namespace Opinie
{
    public partial class MainPage : PhoneApplicationPage
    {
        App myApp = Application.Current as App;

        // Constructor
        public MainPage()
        {
            InitializeComponent();

            myApp.opiniePan = new List<int>();
            myApp.opiniePanow = new List<int>();



            myApp.opiniePanow.Add(1); myApp.opiniePanow.Add(2); myApp.opiniePanow.Add(3); myApp.opiniePanow.Add(4); myApp.opiniePanow.Add(5);
            myApp.opiniePanow.Add(6); myApp.opiniePanow.Add(7); myApp.opiniePanow.Add(8); myApp.opiniePanow.Add(9); myApp.opiniePanow.Add(10);
            myApp.opiniePanow.Add(1); myApp.opiniePanow.Add(2); myApp.opiniePanow.Add(3); myApp.opiniePanow.Add(4); myApp.opiniePanow.Add(5);
            myApp.opiniePanow.Add(6); myApp.opiniePanow.Add(7); myApp.opiniePanow.Add(8); myApp.opiniePanow.Add(9);
            myApp.opiniePanow.Add(5); myApp.opiniePanow.Add(5); myApp.opiniePanow.Add(5); myApp.opiniePanow.Add(5); myApp.opiniePanow.Add(5);
            // Sample code to localize the ApplicationBar
            //BuildLocalizedApplicationBar();
        }

        private void panie_Click(object sender, RoutedEventArgs e)
        {
            myApp.panie = true;
            NavigationService.Navigate(new Uri("/opinie.xaml", UriKind.Relative));
        }


        private void panowie_Click(object sender, RoutedEventArgs e)
        {
            myApp.panie = false;
            NavigationService.Navigate(new Uri("/opinie.xaml", UriKind.Relative));
        }

        private void dodaj_Click(object sender, RoutedEventArgs e)
        {
            if ((bool)radiopan.IsChecked)
                myApp.opiniePanow.Add((int)liczba.Value);
            if ((bool)radiopani.IsChecked)
                myApp.opiniePan.Add((int)liczba.Value);
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
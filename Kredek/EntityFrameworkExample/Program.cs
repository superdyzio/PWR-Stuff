using System;
using System.Windows.Forms;
using Ninject;

namespace Example
{
    public static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        private static readonly IKernel Kernel;

        static Program()
        {
            Kernel = new StandardKernel();
        }

        [STAThread]
        private static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //tutaj tworzymy nasz kontener IoC, wczytujemy i na samym końcu (2 ostatnie linijki) odpalamy Form1
            NinjectContainer nc = new NinjectContainer(Kernel);
            nc.Load();

            var form = Kernel.Get<Form1>();
            Application.Run(form);
        }
    }
}

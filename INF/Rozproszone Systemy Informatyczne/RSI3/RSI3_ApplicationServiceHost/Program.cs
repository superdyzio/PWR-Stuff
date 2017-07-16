using RSI3_ApplicationServiceContract;
using System;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace RSI3_ApplicationServiceHost
{
    class Program
    {
        static void Main(string[] args)
        {
            Uri baseAddress = new Uri("http://localhost:10001/RSI3/");
            ServiceHost host = new ServiceHost(typeof(ApplicationService), baseAddress);

            try
            {
                host.AddServiceEndpoint(typeof(IApplicationService), new WSHttpBinding(), "ApplicationService");

                ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
                smb.HttpGetEnabled = true;
                host.Description.Behaviors.Add(smb);

                host.Open();
                Console.WriteLine("ApplicationService working on port 10001.");
                Console.WriteLine("Press <ENTER> to exit.");
                Console.WriteLine();
                Console.ReadLine();
                host.Close();
            }
            catch (CommunicationException ce)
            {
                Console.WriteLine("Exception: {0}", ce.Message);
                host.Abort();
            }
        }
    }
}

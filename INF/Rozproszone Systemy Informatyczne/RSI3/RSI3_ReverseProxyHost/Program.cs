using System;
using RSI3_ReverseProxyContract;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace RSI3_ReverseProxyHost
{
    class Program
    {
        static void Main(string[] args)
        {
            Uri baseAddress = new Uri("http://localhost:10003/RSI3/");
            ServiceHost host = new ServiceHost(typeof(ReverseProxy), baseAddress);

            try
            {
            
                host.AddServiceEndpoint(typeof(IReverseProxy), new WSHttpBinding(), "ReverseProxy");

                ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
                smb.HttpGetEnabled = true;
                host.Description.Behaviors.Add(smb);

                host.Open();
                Console.WriteLine("ReverseProxy working on port 10003.");
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

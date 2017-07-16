using System;
using RSI3_CachingProxyContract;
using System.ServiceModel;
using System.ServiceModel.Description;

namespace RSI3_CachingProxyHost
{
    class Program
    {
        static void Main(string[] args)
        {
            Uri baseAddress = new Uri("http://localhost:10002/RSI3/");
            ServiceHost host = new ServiceHost(typeof(CachingProxy), baseAddress);

            try
            {
                host.AddServiceEndpoint(typeof(ICachingProxy), new WSHttpBinding(), "CachingProxy");

                ServiceMetadataBehavior smb = new ServiceMetadataBehavior();
                smb.HttpGetEnabled = true;
                host.Description.Behaviors.Add(smb);

                host.Open();
                Console.WriteLine("CachingProxy working on port 10002.");
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

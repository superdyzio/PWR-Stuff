using RSI3_ClientHost.ReverseProxyReference;

namespace RSI3_ClientHost
{
    class Program
    {
        static void Main(string[] args)
        {
            ReverseProxyClient client = new ReverseProxyClient();

            Resource res1 = new Resource();
            res1.Uri = "res1";
            res1.Value = 100;
            Resource res2 = new Resource();
            res2.Uri = "res2";
            res2.Value = 200;
            
            client.create(res1);    // 201
            client.create(res2);    // 201
            client.create(res2);    // 403
            
            client.get("res3");     // null
            client.get("res1");     // res1 from ApplicationServer
            client.get("res1");     // res1 from CachingProxy
            
            client.Close();
        }
    }
}

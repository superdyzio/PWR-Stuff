using System;
using RSI3_ReverseProxyContract.ApplicationServiceReference;
using RSI3_ReverseProxyContract.CachingProxyReference;

namespace RSI3_ReverseProxyContract
{
    public class ReverseProxy : IReverseProxy
    {
        public Resource get(string uri)
        {
            Console.WriteLine("ReverseProxy.get: {0}", uri);
            CachingProxyClient client = new CachingProxyClient();
            CachingProxyReference.Resource tempResource = client.get(uri);
            client.Close();

            Console.WriteLine("ReverseProxy.create: {0} {1}", tempResource.Uri, tempResource.Value);

            Resource resource = new Resource();
            resource.Uri = tempResource.Uri;
            resource.Value = tempResource.Value;

            Console.WriteLine("ReverseProxy.create: {0} {1}", resource.Uri, resource.Value);

            Console.WriteLine("ReverseProxy.get= {0}", resource == null);
            return resource;
        }
    
        public int create(Resource res)
        {
            Console.WriteLine("ReverseProxy.create: {0} {1}", res.Uri, res.Value);
            ApplicationServiceClient client = new ApplicationServiceClient();

            ApplicationServiceReference.Resource resource = new ApplicationServiceReference.Resource();
            resource.Uri = res.Uri;
            resource.Value = res.Value;

            int status = client.create(resource);
            client.Close();

            Console.WriteLine("ReverseProxy.create= {0}", status);
            return status;
        }
    }
}

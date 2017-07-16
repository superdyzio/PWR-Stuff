using System;
using System.Collections.Generic;
using RSI3_CachingProxyContract.ApplicationServiceReference;

namespace RSI3_CachingProxyContract
{
    public class CachingProxy : ICachingProxy
    {
        List<Resource> listOfCachedResources = new List<Resource>();

        public Resource get(string uri)
        {
            Console.WriteLine("CachingProxy.get: {0}", uri);
            Resource resource = null;

            foreach (Resource res in listOfCachedResources)
            {
                resource = res.Uri.Equals(uri) ? resource : null;
            }

            if (resource == null)
            {
                Console.WriteLine("Resource not cached - calling ApplicationService.get");

                ApplicationServiceClient client = new ApplicationServiceClient();
                ApplicationServiceReference.Resource tempResource = client.get(uri);
                client.Close();

                resource.Uri = tempResource.Uri;
                resource.Value = tempResource.Value;
            }

            Console.WriteLine("CachingProxy.get= {0}", resource == null);
            return resource;
        }
    }
}

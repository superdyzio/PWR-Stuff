using System;
using System.Collections.Generic;

namespace RSI3_ApplicationServiceContract
{
    public class ApplicationService : IApplicationService
    {
        List<Resource> listOfResources = new List<Resource>();

        public Resource get(string uri)
        {
            Console.WriteLine("ApplicationService.get: {0}", uri);
            Resource resource = null;

            foreach (Resource res in listOfResources)
            {
                resource = res.Uri.Equals(uri) ? resource : null;
            }

            Console.WriteLine("ApplicationService.get= {0}", resource == null);
            return resource;
        }

        public int create(Resource res)
        {
            Console.WriteLine("ApplicationService.create: {0} {1}", res.Uri, res.Value);

            foreach (Resource resource in listOfResources)
            {
                if (res.Uri.Equals(resource.Uri))
                {
                    Console.WriteLine("ApplicationService.create= 403");
                    return 403;
                }
            }

            Console.WriteLine("ApplicationService.create= 201");
            return 201;
        }
    }
}

using System.ServiceModel;
using System.Runtime.Serialization;

namespace RSI3_ReverseProxyContract
{
    [ServiceContract]
    public interface IReverseProxy
    {
        [OperationContract]
        Resource get(string uri);

        [OperationContract]
        int create(Resource res);
    }

    [DataContract]
    public class Resource
    {
        string uri;
        int value;

        [DataMember]
        public string Uri
        {
            get { return uri; }
            set { uri = value; }
        }

        [DataMember]
        public int Value
        {
            get { return value; }
            set { this.value = value; }
        }
    }
}

using System.Runtime.Serialization;
using System.ServiceModel;

namespace RSI3_CachingProxyContract
{
    [ServiceContract]
    public interface ICachingProxy
    {
        [OperationContract]
        Resource get(string uri);
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

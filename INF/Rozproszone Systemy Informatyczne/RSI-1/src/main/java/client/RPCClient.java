package client;

import org.apache.xmlrpc.client.TimingOutCallback;
import org.apache.xmlrpc.client.XmlRpcClient;
import org.apache.xmlrpc.client.XmlRpcClientConfigImpl;

import java.net.URL;
import java.util.Arrays;


public class RPCClient {
    public static void main(String[] args) throws Throwable {
        XmlRpcClientConfigImpl config = new XmlRpcClientConfigImpl();

        config.setServerURL(new URL("http://localhost:10000"));
        config.setEnabledForExtensions(true);
        config.setConnectionTimeout(1000);

        XmlRpcClient client = new XmlRpcClient();
        client.setConfig(config);

        TimingOutCallback cb1 = new TimingOutCallback(1000); // timeout w milisekundach
        TimingOutCallback cb2 = new TimingOutCallback(1000); // timeout w milisekundach
        TimingOutCallback cb3 = new TimingOutCallback(1000); // timeout w milisekundach
        TimingOutCallback cb4 = new TimingOutCallback(1000); // timeout w milisekundach
        TimingOutCallback cb5 = new TimingOutCallback(1000); // timeout w milisekundach
        TimingOutCallback cb6 = new TimingOutCallback(1000); // timeout w milisekundach

        long startAsync = System.currentTimeMillis();

        client.executeAsync("server.RepositoryProxy.whereIs", Arrays.asList("github3"), cb1);
        client.executeAsync("server.RepositoryProxy.whereIs", Arrays.asList("repozytorium15"), cb2);
        client.executeAsync("server.RepositoryProxy.whereIs", Arrays.asList("sourceforge1"), cb3);
        client.executeAsync("server.RepositoryProxy.getAuthorWithMostCommits", Arrays.asList("github4"), cb4);
        client.executeAsync("server.RepositoryProxy.getAuthorWithMostCommits", Arrays.asList("bitbucket1"), cb5);
        client.executeAsync("server.RepositoryProxy.getAuthorWithMostCommits", Arrays.asList("sourceforge2"), cb6);

        String res1 = (String) cb1.waitForResponse();
        String res2 = (String) cb2.waitForResponse();
        String res3 = (String) cb3.waitForResponse();
        String res4 = (String) cb4.waitForResponse();
        String res5 = (String) cb5.waitForResponse();
        String res6 = (String) cb6.waitForResponse();
        long endAsync = System.currentTimeMillis();

        System.out.println(res1);
        System.out.println(res2);
        System.out.println(res3);
        System.out.println(res4);
        System.out.println(res5);
        System.out.println(res6);

        System.out.println(String.format("Asynchroniczne wywołania trwały: %d ms", endAsync - startAsync));
    }
}

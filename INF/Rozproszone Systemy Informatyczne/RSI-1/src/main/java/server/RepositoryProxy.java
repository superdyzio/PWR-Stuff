package server;

import org.apache.xmlrpc.client.XmlRpcClient;
import org.apache.xmlrpc.client.XmlRpcClientConfigImpl;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.server.XmlRpcStreamServer;
import org.apache.xmlrpc.webserver.WebServer;

import java.net.URL;
import java.util.Arrays;

/**
 * Created by Dyzio on 13.03.2017.
 */
public class RepositoryProxy {
    private static XmlRpcClient github = new XmlRpcClient();
    private static XmlRpcClient bitbucket = new XmlRpcClient();
    private static XmlRpcClient sourceforge = new XmlRpcClient();

    public String whereIs(String repoName) throws Throwable {
        String[] result = new String[3];
        result[0] = (String) github.execute("server.GitHubServer.hasRepo", Arrays.asList(repoName));
        result[1] = (String) bitbucket.execute("server.BitbucketServer.hasRepo", Arrays.asList(repoName));
        result[2] = (String) sourceforge.execute("server.SourceForgeServer.hasRepo", Arrays.asList(repoName));
        switch (Arrays.asList(result).indexOf("Repozytorium znalezione.")) {
            case 0:
                return "GitHub";
            case 1:
                return "Bitbucket";
            case 2:
                return "SourceForge";
            default:
                return "Nie znaleziono repozytorium.";
        }
    }

    public String getAuthorWithMostCommits(String repoName) throws Throwable {
        String[] repos = new String[3];
        repos[0] = (String) github.execute("server.GitHubServer.hasRepo", Arrays.asList(repoName));
        repos[1] = (String) bitbucket.execute("server.BitbucketServer.hasRepo", Arrays.asList(repoName));
        repos[2] = (String) sourceforge.execute("server.SourceForgeServer.hasRepo", Arrays.asList(repoName));
        switch (Arrays.asList(repos).indexOf("Repozytorium znalezione.")) {
            case 0:
                return (String) github.execute("server.GitHubServer.getAuthorWithMostCommits", Arrays.asList(repoName));
            case 1:
                return (String) bitbucket.execute("server.BitbucketServer.getAuthorWithMostCommits", Arrays.asList(repoName));
            case 2:
                return (String) sourceforge.execute("server.SourceForgeServer.getAuthorWithMostCommits", Arrays.asList(repoName));
            default:
                return "Nie znaleziono repozytorium.";
        }
    }

    public static void main(String[] args) throws Throwable {
        XmlRpcClientConfigImpl githubConfig = new XmlRpcClientConfigImpl();
        XmlRpcClientConfigImpl bitbucketConfig = new XmlRpcClientConfigImpl();
        XmlRpcClientConfigImpl sourceforgeConfig = new XmlRpcClientConfigImpl();

        githubConfig.setServerURL(new URL("http://localhost:10001"));
        githubConfig.setEnabledForExtensions(true);
        githubConfig.setConnectionTimeout(1000);

        bitbucketConfig.setServerURL(new URL("http://localhost:10002"));
        bitbucketConfig.setEnabledForExtensions(true);
        bitbucketConfig.setConnectionTimeout(1000);

        sourceforgeConfig.setServerURL(new URL("http://localhost:10003"));
        sourceforgeConfig.setEnabledForExtensions(true);
        sourceforgeConfig.setConnectionTimeout(1000);

        github.setConfig(githubConfig);
        bitbucket.setConfig(bitbucketConfig);
        sourceforge.setConfig(sourceforgeConfig);


        WebServer server = new WebServer(10000);

        XmlRpcStreamServer rpcServer = server.getXmlRpcServer();
        PropertyHandlerMapping handlers = new PropertyHandlerMapping();
        handlers.addHandler(RepositoryProxy.class.getName(), RepositoryProxy.class);
        rpcServer.setHandlerMapping(handlers);

        System.out.println("Repository proxy działa!");
        server.start();
    }
}

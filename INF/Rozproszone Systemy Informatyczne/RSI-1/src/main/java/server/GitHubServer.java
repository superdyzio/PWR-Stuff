package server;

import core.Repository;
import org.apache.xmlrpc.XmlRpcException;
import org.apache.xmlrpc.server.PropertyHandlerMapping;
import org.apache.xmlrpc.server.XmlRpcStreamServer;
import org.apache.xmlrpc.webserver.WebServer;

import java.io.IOException;

/**
 * Created by Dyzio on 13.03.2017.
 */
public class GitHubServer extends RepoServer {
    public GitHubServer() {
        super();
        this.repoList.add(new Repository("github1", "Dawid"));
        this.repoList.add(new Repository("github2", "Mateusz"));
        this.repoList.add(new Repository("github3", "Dawid"));
        this.repoList.add(new Repository("github4", "Adam"));
    }

    public static void main(String[] args) throws XmlRpcException, IOException {
        WebServer server = new WebServer(10001);

        XmlRpcStreamServer rpcServer = server.getXmlRpcServer();
        PropertyHandlerMapping handlers = new PropertyHandlerMapping();
        handlers.addHandler(GitHubServer.class.getName(), GitHubServer.class);
        rpcServer.setHandlerMapping(handlers);

        System.out.println("Serwer GitHub działa!");
        server.start();
    }
}

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
public class BitbucketServer extends RepoServer {
    public BitbucketServer() {
        super();
        this.repoList.add(new Repository("bitbucket1", "Adam"));
        this.repoList.add(new Repository("bitbucket2", "Mateusz"));
    }

    public static void main(String[] args) throws XmlRpcException, IOException {
        WebServer server = new WebServer(10002);

        XmlRpcStreamServer rpcServer = server.getXmlRpcServer();
        PropertyHandlerMapping handlers = new PropertyHandlerMapping();
        handlers.addHandler(BitbucketServer.class.getName(), BitbucketServer.class);
        rpcServer.setHandlerMapping(handlers);

        System.out.println("Serwer Bitbucket działa!");
        server.start();
    }
}

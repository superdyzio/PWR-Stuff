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
public class SourceForgeServer extends RepoServer {
    public SourceForgeServer() {
        super();
        this.repoList.add(new Repository("sourceforge1", "Mateusz"));
        this.repoList.add(new Repository("sourceforge2", "Adam"));
        this.repoList.add(new Repository("sourceforge3", "Dawid"));
    }

    public static void main(String[] args) throws XmlRpcException, IOException {
        WebServer server = new WebServer(10003);

        XmlRpcStreamServer rpcServer = server.getXmlRpcServer();
        PropertyHandlerMapping handlers = new PropertyHandlerMapping();
        handlers.addHandler(SourceForgeServer.class.getName(), SourceForgeServer.class);
        rpcServer.setHandlerMapping(handlers);

        System.out.println("Serwer SourceForge działa!");
        server.start();
    }
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;  
import java.io.OutputStream;  
import java.io.PrintWriter;  
import java.sql.Time;
import java.util.ArrayList;

import org.apache.commons.cli.CommandLine;  
import org.apache.commons.cli.CommandLineParser;  
import org.apache.commons.cli.GnuParser;  
import org.apache.commons.cli.HelpFormatter;  
import org.apache.commons.cli.Options;  
import org.apache.commons.cli.ParseException;  
import org.apache.commons.cli.PosixParser;  

import edu.uci.ics.jung.algorithms.shortestpath.PrimMinimumSpanningTree;
import edu.uci.ics.jung.graph.DelegateTree;
import edu.uci.ics.jung.graph.DirectedGraph;
import edu.uci.ics.jung.graph.DirectedSparseMultigraph;
import edu.uci.ics.jung.graph.Graph;

/** 
 * Main example demonstrating Apache Commons CLI.  Apache Commons CLI and more 
 * details on it are available at http://commons.apache.org/cli/. 
 *  
 * @author Dustin 
 */  
public class MainCliExample  
{  
	private static Options options = new Options();  

	/** 
	 * Apply Apache Commons CLI PosixParser to command-line arguments. 
	 *  
	 * @param commandLineArguments Command-line arguments to be processed with 
	 *    Posix-style parser. 
	 * @throws IOException 
	 */  
	public static void usePosixParser(final String[] commandLineArguments) throws IOException  
	{  
		final CommandLineParser cmdLinePosixParser = new PosixParser();  
		final Options posixOptions = constructPosixOptions();  
		CommandLine commandLine;
		String sciezka = null;
		NaszGraph graf = null;
		try  
		{  
			commandLine = cmdLinePosixParser.parse(posixOptions, commandLineArguments);  
			if ( commandLine.hasOption("i") || commandLine.hasOption("input") )  
			{  
				String plik = commandLine.getOptionValue("i") == null ? commandLine.getOptionValue("input") : commandLine.getOptionValue("i");
				File file = new File(plik);
				BufferedReader reader = new BufferedReader(new FileReader(file));
				ArrayList<String> lista = new ArrayList<String>();
				String line = null;
				LazyPrimMinimumSpanningTree drzewo = null;
				while((line = reader.readLine()) != null){
					lista.add(line);
				}
				if ( commandLine.hasOption("d") || commandLine.hasOption("dijkstra"))
				{
					graf = new NaszGraph(lista.size());
					for (String s:lista) {
						String[] tab = s.split(" ");
						graf.addEdge(new Edge(Integer.parseInt(tab[0]),Integer.parseInt(tab[1]),Integer.parseInt(tab[2])));
						graf.addEdge(new Edge(Integer.parseInt(tab[1]),Integer.parseInt(tab[0]),Integer.parseInt(tab[2])));
					} // przerabia³em algorytm dijkstra dla grafu skierowanego, dlatego dodaje ka¿d¹ krawêdŸ "w obie strony"
					  // dziêki temu mam odpowiednik grafu nieskierowanego
					int poczatek = 0, koniec = 0;
					long czasD = 0, czasW = 0, start = 0, stop = 0;
					if ( commandLine.hasOption("f") || commandLine.hasOption("from"))
					{
						String pom = commandLine.getOptionValue("f")==null ? commandLine.getOptionValue("from") : commandLine.getOptionValue("f");
						poczatek = Integer.parseInt(pom);
					}
					if ( commandLine.hasOption("t") || commandLine.hasOption("to"))
					{
						String pom = commandLine.getOptionValue("t")==null ? commandLine.getOptionValue("to") : commandLine.getOptionValue("t");
						koniec = Integer.parseInt(pom);
					}
					start = System.nanoTime();
					Dijkstra dj = new Dijkstra(graf,poczatek);
					int waga = 0;
					for (Edge e:dj.getPathTo(koniec)) {
						waga += e.getWeight();
					}
					stop = System.nanoTime();
					czasD = stop - start;
					if ( commandLine.hasOption("v") || commandLine.hasOption("verify"))  
					{  
						start = System.nanoTime();
						stop = System.nanoTime();
						czasW = stop - start;
						System.out.printf("Czas wykonania algorytmu: %f [ms]\nCzas wykonania weryfikacji: %f [ms]\n",czasD/Math.pow(10,6),czasW/Math.pow(10,6));
					}
					if ( commandLine.hasOption("o") || commandLine.hasOption("output"))  
					{  
						sciezka = commandLine.getOptionValue("o") == null ? commandLine.getOptionValue("output") : commandLine.getOptionValue("o");
					}  
					if ( commandLine.hasOption("c") || commandLine.hasOption("console"))  
					{  
						if (dj != null) sciezka = "";
						else System.out.println("Nie wybrano algorytmu przechodzenia grafu.");
					}
					if (sciezka != null)
						if (!sciezka.isEmpty()){
							File plik2 = new File(sciezka);
							BufferedWriter wyj = new BufferedWriter(new FileWriter(plik2));
							wyj.write(String.format("%d",waga));
							wyj.flush();
						}
						else {
							System.out.println(waga);
						}
				}
				else {
					if ( commandLine.hasOption("p") || commandLine.hasOption("prim")) 
					{
						double czasP, czasV; 
						long start, stop;
						start = System.nanoTime();
						graf = new NaszGraph(lista.size());
						for (String s:lista) {
							String[] tab = s.split(" ");
							graf.addEdge(new Edge(Integer.parseInt(tab[0]),Integer.parseInt(tab[1]),Integer.parseInt(tab[2])));
						}
						drzewo = new LazyPrimMinimumSpanningTree(graf);
						stop = System.nanoTime();
						czasP = stop - start;
						if ( commandLine.hasOption("v") || commandLine.hasOption("verify"))  
						{  
							File plik3 = new File(commandLine.getOptionValue("v") == null ? commandLine.getOptionValue("verify") : commandLine.getOptionValue("v"));
							BufferedWriter dopliku = new BufferedWriter(new FileWriter(plik3));
							start = System.nanoTime();
							DirectedGraph<Integer,Integer> graph = new DirectedSparseMultigraph<Integer,Integer>();
							int i = 0;
							for (String s:lista) {
								String[] tab = s.split(" ");
								graph.addEdge(i++,Integer.parseInt(tab[0]),Integer.parseInt(tab[1]));
							}

							//		System.err.println("graph = "+graph);
							PrimMinimumSpanningTree<Integer,Integer> pmst = 
									new PrimMinimumSpanningTree<Integer,Integer>(DelegateTree.<Integer,Integer>getFactory());

							Graph<Integer,Integer> mst = pmst.transform(graph);
							stop = System.nanoTime();
							dopliku.write(""+mst);
							dopliku.flush();
							dopliku.close();
							//	for ( Integer v : mst.getVertices() )
							{
								//		mst.
							}
							//							System.out.println("mst = "+mst);
							czasV = stop - start;
							System.out.printf("Czas wykonania algorytmu: %f [ms]\nCzas wykonania weryfikacji: %f [ms]\n",czasP/Math.pow(10,6),czasV/Math.pow(10,6));
						}
					}
					if ( commandLine.hasOption("o") || commandLine.hasOption("output"))  
					{  
						sciezka = commandLine.getOptionValue("o") == null ? commandLine.getOptionValue("output") : commandLine.getOptionValue("o");
					}  
					if ( commandLine.hasOption("c") || commandLine.hasOption("console"))  
					{  
						if (drzewo != null) sciezka = "";
						else System.out.println("Nie wybrano algorytmu przechodzenia grafu.");
					}
					if (sciezka != null)
						if (!sciezka.isEmpty()){
							File plik2 = new File(sciezka);
							BufferedWriter wyj = new BufferedWriter(new FileWriter(plik2));
							drzewo.sort();
							for (Edge e:drzewo.edges()) {
								wyj.append(e.toString()+"\r\n");
							}
							wyj.flush();
						}
						else {
							for (Edge e:drzewo.edges())
								System.out.println(e.toString());
						}
				}
			}
			else System.out.println("Brak opcji -i.");
		}  
		catch (ParseException parseException)  // checked exception  
		{  
			System.err.println(  
					"Encountered exception while parsing using PosixParser:\n"  
							+ parseException.getMessage() );  
		}  
	}  

	/** 
	 * Apply Apache Commons CLI GnuParser to command-line arguments. 
	 *  
	 * @param commandLineArguments Command-line arguments to be processed with 
	 *    Gnu-style parser. 
	 * @throws IOException 
	 */  
	public static void useGnuParser(final String[] commandLineArguments) throws IOException  
	{  
		final CommandLineParser cmdLineGnuParser = new GnuParser();  

		final Options gnuOptions = constructGnuOptions();  
		CommandLine commandLine;
		String sciezka = null;
		NaszGraph graf;
		try  
		{  
			commandLine = cmdLineGnuParser.parse(gnuOptions, commandLineArguments);  
			if ( commandLine.hasOption("i") || commandLine.hasOption("input") )  
			{  
				String plik = commandLine.getOptionValue("i") == null ? commandLine.getOptionValue("input") : commandLine.getOptionValue("i");
				File file = new File(plik);
				BufferedReader reader = new BufferedReader(new FileReader(file));
				ArrayList<String> lista = new ArrayList<String>();
				String line = null;
				LazyPrimMinimumSpanningTree drzewo = null;
				while((line = reader.readLine()) != null){
					lista.add(line);
				}
				if ( commandLine.hasOption("d") || commandLine.hasOption("dijkstra"))
				{
					if ( commandLine.hasOption("f") || commandLine.hasOption("from"))
					{
					}
					if ( commandLine.hasOption("t") || commandLine.hasOption("to"))
					{
					}
					if ( commandLine.hasOption("v") || commandLine.hasOption("verify"))  
					{  
					}
				}
				else
					if ( commandLine.hasOption("p") || commandLine.hasOption("prim")) 
					{
						graf = new NaszGraph(lista.size());
						for (String s:lista) {
							String[] tab = s.split(" ");
							graf.addEdge(new Edge(Integer.parseInt(tab[0]),Integer.parseInt(tab[1]),Integer.parseInt(tab[2])));
						}
						drzewo = new LazyPrimMinimumSpanningTree(graf);
						if ( commandLine.hasOption("v") || commandLine.hasOption("verify"))  
						{  
							DirectedGraph<Integer,Integer> graph = new DirectedSparseMultigraph<Integer,Integer>();


							for (String s:lista) {
								String[] tab = s.split(" ");
								graph.addEdge(Integer.parseInt(tab[2]),Integer.parseInt(tab[0]),Integer.parseInt(tab[1]));
							}

							//		System.err.println("graph = "+graph);
							PrimMinimumSpanningTree<Integer,Integer> pmst = 
									new PrimMinimumSpanningTree<Integer,Integer>(DelegateTree.<Integer,Integer>getFactory());

							Graph<Integer,Integer> mst = pmst.transform(graph);

							//	for ( Integer v : mst.getVertices() )
							{
								//		mst.
							}
							System.out.println("mst = "+mst);
						}
					}
				if ( commandLine.hasOption("o") || commandLine.hasOption("output"))  
				{  
					sciezka = commandLine.getOptionValue("o") == null ? commandLine.getOptionValue("output") : commandLine.getOptionValue("o");
				}  
				if ( commandLine.hasOption("c") || commandLine.hasOption("console"))  
				{  
					sciezka = "";
				}
				if (sciezka != null)
					if (!sciezka.isEmpty()){
						File plik2 = new File(sciezka);
						BufferedWriter wyj = new BufferedWriter(new FileWriter(plik2));
						for (Edge e:drzewo.edges()) 
							wyj.append(e.toString());
						wyj.flush();
					}
					else {
						for (Edge e:drzewo.edges())
							System.out.println(e.toString());
					}

			}      
		}  
		catch (ParseException parseException)  // checked exception  
		{  
			System.err.println(  
					"Encountered exception while parsing using GnuParser:\n"  
							+ parseException.getMessage() );  
		}  
	}  

	/** 
	 * Construct and provide Posix-compatible Options. 
	 *  
	 * @return Options expected from command-line of Posix form. 
	 */  
	public static Options constructPosixOptions()  
	{  
		final Options posixOptions = new Options();  
		posixOptions.addOption("i", "input", true, "sciezka do pliku z grafem")  
		.addOption("o", "output", true, "sciezka do pliku wyjsciowego")  
		.addOption("c", "console", false, "wydruk na konsole")
		.addOption("v", "verify", true, "sciezka do pliku wyjsciowego")
		.addOption("p", "prim", false, "wywolanie algorytmu prima")
		.addOption("d", "dijkstra", false, "wywolanie algorytmu dijkstra")
		.addOption("f", "from", true, "wierzcholek poczatkowy")
		.addOption("t", "to", true, "wierzcholek koncowy");  
		return posixOptions;  
	}  

	/** 
	 * Construct and provide GNU-compatible Options. 
	 *  
	 * @return Options expected from command-line of GNU form. 
	 */  
	public static Options constructGnuOptions()  
	{  
		final Options gnuOptions = new Options();  
		gnuOptions.addOption("i", "input", true, "sciezka do pliku z grafem")  
		.addOption("o", "output", true, "sciezka do pliku wyjsciowego")  
		.addOption("c", "console", false, "wydruk na konsole")
		.addOption("v", "verify", true, "sciezka do pliku wyjsciowego")
		.addOption("p", "prim", false, "wywolanie algorytmu prima")
		.addOption("d", "dijkstra", false, "wywolanie algorytmu dijkstra")
		.addOption("f", "from", true, "wierzcholek poczatkowy")
		.addOption("t", "to", true, "wierzcholek koncowy");
		return gnuOptions;  
	}  

	/** 
	 * Display command-line arguments without processing them in any further way. 
	 *  
	 * @param commandLineArguments Command-line arguments to be displayed. 
	 */  
	public static void displayProvidedCommandLineArguments(  
			final String[] commandLineArguments,  
			final OutputStream out)  
	{  
		final StringBuffer buffer = new StringBuffer();  
		for ( final String argument : commandLineArguments )  
		{  
			buffer.append(argument).append(" ");  
		}  
		try  
		{  
			out.write((buffer.toString() + "\n").getBytes());  
		}  
		catch (IOException ioEx)  
		{  
			System.err.println(  
					"WARNING: Exception encountered trying to write to OutputStream:\n"  
							+ ioEx.getMessage() );  
			System.out.println(buffer.toString());  
		}  
	}  

	/** 
	 * Display example application header. 
	 *  
	 * @out OutputStream to which header should be written. 
	 */  
	public static void displayHeader(final OutputStream out)  
	{  
		final String header =  
				"[Apache Commons CLI Example from Dustin's Software Development "  
						+ "Cogitations and Speculations Blog]\n";  
		try  
		{  
			out.write(header.getBytes());  
		}  
		catch (IOException ioEx)  
		{  
			System.out.println(header);  
		}  
	}  

	/** 
	 * Write the provided number of blank lines to the provided OutputStream. 
	 *  
	 * @param numberBlankLines Number of blank lines to write. 
	 * @param out OutputStream to which to write the blank lines. 
	 */  
	public static void displayBlankLines(  
			final int numberBlankLines,  
			final OutputStream out)  
	{  
		try  
		{  
			for (int i=0; i<numberBlankLines; ++i)  
			{  
				out.write("\n".getBytes());  
			}  
		}  
		catch (IOException ioEx)  
		{  
			for (int i=0; i<numberBlankLines; ++i)  
			{  
				System.out.println();  
			}  
		}  
	}  

	/** 
	 * Print usage information to provided OutputStream. 
	 *  
	 * @param applicationName Name of application to list in usage. 
	 * @param options Command-line options to be part of usage. 
	 * @param out OutputStream to which to write the usage information. 
	 */  
	public static void printUsage(  
			final String applicationName,  
			final Options options,  
			final OutputStream out)  
	{  
		final PrintWriter writer = new PrintWriter(out);  
		final HelpFormatter usageFormatter = new HelpFormatter();  
		usageFormatter.printUsage(writer, 80, applicationName, options);  
		writer.flush();  
	}  

	/** 
	 * Write "help" to the provided OutputStream. 
	 */  
	public static void printHelp(  
			final Options options,  
			final int printedRowWidth,  
			final String header,  
			final String footer,  
			final int spacesBeforeOption,  
			final int spacesBeforeOptionDescription,  
			final boolean displayUsage,  
			final OutputStream out)  
	{  
		final String commandLineSyntax = "java -cp ApacheCommonsCLI.jar";  
		final PrintWriter writer = new PrintWriter(out);  
		final HelpFormatter helpFormatter = new HelpFormatter();  
		helpFormatter.printHelp(  
				writer,  
				printedRowWidth,  
				commandLineSyntax,  
				header,  
				options,  
				spacesBeforeOption,  
				spacesBeforeOptionDescription,  
				footer,  
				displayUsage);  
		writer.flush();  
	}  

	/** 
	 * Main executable method used to demonstrate Apache Commons CLI. 
	 *  
	 * @param commandLineArguments Commmand-line arguments. 
	 * @throws IOException 
	 */  
	public static void main(final String[] commandLineArguments) throws IOException  
	{  
		final String applicationName = "MainCliExample";  
		displayBlankLines(1, System.out);  
		displayHeader(System.out);  
		displayBlankLines(2, System.out);  
		if (commandLineArguments.length < 1)  
		{  
			System.out.println("-- USAGE --");  
			printUsage(applicationName + " (Posix)", constructPosixOptions(), System.out);  
			displayBlankLines(1, System.out);  
			printUsage(applicationName + " (Gnu)", constructGnuOptions(), System.out);  

			displayBlankLines(4, System.out);  

			System.out.println("-- HELP --");  
			printHelp(  
					constructPosixOptions(), 80, "POSIX HELP", "End of POSIX Help",  
					3, 5, true, System.out);  
			displayBlankLines(1, System.out);  
			printHelp(  
					constructGnuOptions(), 80, "GNU HELP", "End of GNU Help",  
					5, 3, true, System.out);  
		}  
		displayProvidedCommandLineArguments(commandLineArguments, System.out);  
		usePosixParser(commandLineArguments);  
		//useGnuParser(commandLineArguments);  
	}  
} 
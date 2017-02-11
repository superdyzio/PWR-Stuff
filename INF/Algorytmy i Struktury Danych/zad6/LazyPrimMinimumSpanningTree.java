import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;


public class LazyPrimMinimumSpanningTree {
	// zawiera flagi, czy dany wierzcholek zostal odwiedzony
	private boolean[] marked;
	// krawedzie minmalnego drzewa rozpinajacego
	private Queue<Edge> minimumSpanningTree;
	// krawedzie przekroju i krawedzie niewybieralne
	private Queue<Edge> priorityQueue;
	// sumaryczna waga drzewa
	private long weight;

	public LazyPrimMinimumSpanningTree(NaszGraph graph) {
		marked = new boolean[graph.getNumberOfVertices()];
		minimumSpanningTree = new LinkedList<Edge>();
		priorityQueue = new PriorityQueue<Edge>(graph.getNumberOfVertices());

		// odwiedzamy pierwszy wierzcholek
		visit(graph, 0);
		while (!priorityQueue.isEmpty()) {
			// pobieramy kolejna krawedz z kolejki priorytetowj
			Edge e = priorityQueue.poll();
			int v = e.getEitherVertex();
			int w = e.getOtherVertex(v);
			// jesli wierzcholki sa oznaczone jako odwiedzone pomijamy reszte
			// instrukcji
			if (marked[v] && marked[w]) {
				continue;
			}
			// dodajemy do drzewa rozpinajacego krawedz
			minimumSpanningTree.offer(e);
//			System.out.print(e);
			// aktualizacja wagi drzewa rozpinajacego
			weight += e.getWeight();

			// dodajemy do drzewa wierzcholki jesli sa nieodwiedzone
			if (!marked[v]) {
				visit(graph, v);
			}
			if (!marked[w]) {
				visit(graph, w);
			}
		}
	}

	/**
	 *
	 * @return iterowalna kolekcje krawedzi wyznaczonego drzewa
	 */
	public Iterable<Edge> edges() {
		return minimumSpanningTree;
	}

	public long getWeight() {
		return weight;
	}

	private void visit(NaszGraph graph, int v) {
		// oznaczamy wierzcholek jako odwiedzony
		marked[v] = true;
		// dodajemy wszystkie nieodwiedzone sasiednie wierzcholki wierzcholka do kolejki priorytetowej
		for (Edge edge : graph.getAdjacencyList(v)) {
			if (!marked[edge.getOtherVertex(v)]) {
				priorityQueue.offer(edge);
			}
		}
	}
	
	public ArrayList<Edge> sort() {
		ArrayList<Edge> wynik = new ArrayList<Edge>();
		Edge min = null;
		for (Edge e:minimumSpanningTree) {
		}
		return wynik;
	}
}
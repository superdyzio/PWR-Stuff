import java.util.ArrayList;
import java.util.List;

class NaszGraph {
	// liczba wierzcholkow
	private final int v;
	// liczba krawedzi
	private int e;
	// listy sasiedztwa
	private List<Edge>[] adjacencyLists;

	@SuppressWarnings("unchecked")
	public NaszGraph(int v) {
		this.v = v;
		this.e = 0;
		this.adjacencyLists = (List<Edge>[]) new List[v];
		for (int i = 0; i < v; i++) {
			adjacencyLists[i] = new ArrayList<Edge>();
		}
	}

	/**
	 *
	 * @return liczbe krawedzi w grafie
	 */
	public int getNumberOfEdges() {
		return e;
	}

	/**
	 *
	 * @return liczbe wierzcholkow w grafie
	 */
	public int getNumberOfVertices() {
		return v;
	}

	/**
	 * Dodaje krawedz do odpowiednich list sasiedztwa(obu koncow krawedzi).
	 *
	 * @param edge
	 *            krawedz, ktora ma zostac dodana do grafu
	 */
	public void addEdge(Edge edge) {
		int v = edge.getEitherVertex();
		int w = edge.getOtherVertex(v);
		adjacencyLists[v].add(edge);
		adjacencyLists[w].add(edge);
		e++;
	}

	/**
	 * Zwraca liste sasiedztwa danego wierzcholka.
	 *
	 * @param v
	 *            indeks wierzcholka
	 * @return zwraca iterowalna kolekcje krawedzi
	 */
	public Iterable<Edge> getAdjacencyList(int v) {
		return adjacencyLists[v];
	}
}

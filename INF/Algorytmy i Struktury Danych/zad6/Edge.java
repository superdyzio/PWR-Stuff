class Edge implements Comparable<Edge> {
	// jeden wierzcholek
	private final int v;
	// drugi wierzcholek
	private final int w;
	// waga
	private final long weight;

	public Edge(int v, int w, int weight) {
		this.v = v;
		this.w = w;
		this.weight = weight;
	}

	/**
	 *
	 * @return jeden z wierzcholkow
	 */
	public int getEitherVertex() {
		return v;
	}

	/**
	 *
	 * @param vertex
	 *            jeden z wierzcholkow krawedzi
	 * @return wierzcholek, ktory wspoltworzy krawedz z wierzcholkiem
	 *         {@code vertex}
	 */
	public int getOtherVertex(int vertex) {
		if (vertex == v) {
			return w;
		} else if (vertex == w) {
			return v;
		}
		throw new IllegalArgumentException("Wrong vertex!");
	}

	/**
	 *
	 * @return wage krawedzi
	 */
	public long getWeight() {
		return weight;
	}

	@Override
	public String toString() {
		return String.format("%d %d\n", v, w);
	}

	@Override
	public int compareTo(Edge arg) {
		if (v < arg.v)
			return 1;
		if (v == arg.v && w < arg.w)
			return 1;
		return -1;
	}
	
	public int from() {
		return v;
	}
	
	public int to() {
		return w;
	}
}
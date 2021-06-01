#include "graph.h"
using namespace flab;

graph::graph()
	:n(0) {}

graph::graph(int _n)
	: n(_n), firstEdge(_n, 0), pointTags(_n,"") {}

graph::graph(const graph& b)
	: n(b.n), edges(b.edges), firstEdge(b.firstEdge), pointTags(b.pointTags) {}

graph::graph(graph&& b)
	: n(move(b.n)), edges(move(b.edges)), firstEdge(move(b.firstEdge)), pointTags(move(b.pointTags)) {}

int graph::getNumPoints() {
	return n;
}

void graph::addEdge(int frm, int to, string tag) {
	
}
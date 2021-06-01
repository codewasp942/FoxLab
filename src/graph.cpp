#include "graph.h"
using namespace flab;

graph::graph() {
	n = 0;
	start.clear();
}

graph::graph(int _n):start(_n,nullptr){
	n = _n;
}

graph::graph(const graph& b) {
	n = b.n;
}

graph::graph(graph&& b) {
	n = b.n;
}

int graph::get_num() {
	return n;
}

void graph::add_edge(int frm, int to, string tag) {
	
}
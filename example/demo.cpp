#include <iostream>
#include "foxlab.h"
using namespace flab;
using namespace std;
int main(int argc, char** argv) {
	srand(time(NULL));
	screen scr;
	scr.init(1300, 600);
	scr.fps(1000);
	graph g(0, 0, 900, 600);
	scr.add(&g);

	for (int i = 0; i < 10; i++) {
		g.addPoint();
		scr.wait(100);
	}
	g.addEdge(3, 1);
	g.addEdge(3, 2);
	scr.wait(500);
	g.addEdge(5, 6);
	g.addEdge(6, 7);
	g.addEdge(3, 7);
	scr.wait(500);

	return scr.runTillEnd();
}
#include <iostream>
#include "foxlab.h"
using namespace flab;
using namespace std;
int main(int argc, char** argv) {
	srand(time(NULL));
	screen scr;
	scr.init(500, 500, "I am your father , you are my son!");
	scr.fps(1000);
	cout << "1\n";
	graph g(100,100,300,300);
	cout << "2\n";
	scr.add(&g);
	cout << "3\n";

	for (int i = 0; i < 10; i++) {
		g.addPoint();
	}
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(5, 6);
	g.addEdge(6, 7);


	return scr.runTillEnd();
}
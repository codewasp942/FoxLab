#include "screen.h"
#include "graph.h"
#include <Windows.h>
using namespace flab;
int main(int argc, char** argv) {
	Fl_Window* window = new Fl_Window(500, 500, "111");
	window->end();

	Fl_Widget* wid = new mw(0,0,150,150);
	window->add(wid);
	window->show();
	graph g;
	return Fl::run();
}
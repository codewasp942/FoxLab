#include "screen.h"
using namespace flab;

screen::screen()
	:showed(false), window(nullptr), redrawPerSec(24) {}

bool screen::init(int wide, int height, const char* title) {
	window = new Fl_Double_Window(wide, height, title);
	Fl::add_timeout(1 / redrawPerSec, redraw, this);
	window->end();
	window->show();
	return true;
}

void screen::wait(int ms) {
	int nw = clock();
	while (clock() - nw < ms) {
		Fl::wait();
	}
}

void screen::update() {
	Fl::wait();
}

int screen::runTillEnd() {
	return Fl::run();
}

void screen::add(widgetbase* widget) {
	window->add(widget);
}

void screen::fps(double newfps) { redrawPerSec = newfps; }
double screen::fps() { return redrawPerSec; }
#include "screen.h"
using namespace flab;

screen::screen()
	:showed(false), bgbox(nullptr), window(nullptr), redrawPerSec(24) {}

bool screen::init(int wide, int height, const char* title, Fl_Color background) {
	window = new Fl_Double_Window(wide, height, title);
	bgbox = new Fl_Box(0, 0, wide, height);
	bgbox->color(background);
	bgbox->box(FL_FLAT_BOX);
	Fl::add_timeout(1 / redrawPerSec, updateScr, this);
	window->end();
	window->show();
	return true;
}

void screen::fps(double newfps) { redrawPerSec = newfps; }
double screen::fps() { return redrawPerSec; }

void screen::background(Fl_Color newcol) { bgbox->color(newcol); }
Fl_Color screen::background() { return bgbox->color(); }

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
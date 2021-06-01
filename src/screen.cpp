#include "screen.h"
using namespace flab;

screen::screen() {
	window = nullptr;
}

bool screen::init(int wide, int height, const char* title) {
	window = new Fl_Window(wide, height, title);
	window->end();
	return true;
}
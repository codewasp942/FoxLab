#include "widgetbase.h"
using namespace flab;

widgetbase::widgetbase(int _x, int _y, int _w, int _h, const char* label)
	:x(_x), y(_y), w(_w), h(_h), Fl_Widget(_x, _y, _w, _h, label) {}

void widgetbase::update() {
	
}

void widgetbase::draw() {
	fl_push_clip(x, y, w, h);
	update();
	fl_pop_clip();
}

void widgetbase::circle(int _x, int _y, int _r, Fl_Color _col, int _wide, int _style) {
	fl_begin_loop();
	fl_color(_col);
	fl_line_style(_style, _wide);
	fl_circle(_x + x, _y + y, _r);
	fl_end_loop();
}

void widgetbase::circle_fill(int _x, int _y, int _r, Fl_Color _col) {
	fl_begin_polygon();
	fl_color(_col);
	fl_circle(_x + x, _y + y, _r);
	fl_end_polygon();
}

void widgetbase::rect(int _x, int _y, int _xw, int _yw, Fl_Color _col, int _wide, int _style) {
	fl_line_style(_style, _wide);
	fl_color(_col);
	fl_begin_loop();
	fl_rect(_x + x, _y + y, _xw, _yw);
	fl_end_loop();
}

void widgetbase::rect_fill(int _x, int _y, int _xw, int _yw, Fl_Color _col) {
	fl_begin_polygon();
	fl_color(_col);
	fl_rect(_x + x, _y + y, _xw, _yw);
	fl_end_polygon();
}

void widgetbase::line(int _x1, int _y1, int _x2, int _y2, Fl_Color _col, int _wide, int _style) {
	fl_begin_line();
	fl_color(_col);
	fl_line_style(_style, _wide);
	fl_line(_x1 + x, _y1 + y, _x2 + x, _y2 + y);
	fl_end_line();
}
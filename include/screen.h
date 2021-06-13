#pragma once
#define DLLexport
#define FL_INTERNALS
#include "dllexport.h"
#include "widgetbase.h"
#include <time.h>
#include <vector>
#include <FL/x.H>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>

using std::vector;

/**
 * @file screen.h
 * @brief Screen wrapper class.
 */


class mw : public Fl_Widget {
public:
	mw(int x, int y, int w, int h, const char* label = 0L):Fl_Widget(x,y,w,h,label){
		
	}
	void draw() {
		fl_color(0, 0, 0);
		fl_line(10, 10, 100, 100);
	}
};

namespace flab {

/**
 * @brief Screen class.
 * This class holds a reference to all the data structures that will be displayed.
*/
DLLfrm class screen {
public:
	screen();

	/**
	 * @brief Create window.
	 * @param wide Wide of the window
	 * @param height Height of the window
	 * @return Is init successed
	 *   @retval If successed , return true
	*/
	bool init(int wide, int height, const char* title = "FoxLab view");

	/**
	 * @brief Wait some time
	 * @param ms Time to wait
	*/
	void wait(int ms);
	/**
	 * @brief Update window
	*/
	void update();
	/**
	 * @brief Run till the end.
	 * @return Return value.
	 * example:
	 *     return scr.runTillEnd();
	*/
	int runTillEnd();

	/**
	 * @brief Add a widget.
	 * The widgets added later will be displayed on the upper layer.
	 * @param widget widget to be added , must inherit from class widgetbase
	*/
	void add(widgetbase* widget);

	/**
	 * @brief Set FPS.
	 * @param newfps new FPS value
	*/
	void fps(double newfps);
	/**
	 * @brief Get FPS.
	 * @return FPS value
	*/
	double fps();
	
private:

	friend void redraw(void* args) {
		screen* w = (screen*)args;
		w->window->redraw();
		Fl::add_timeout(1 / w->redrawPerSec, redraw, args);
	}

	Fl_Double_Window* window;
	bool showed;

	double redrawPerSec;

};

}
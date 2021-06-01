#pragma once
#define DLLexport
#include "dllexport.h"

/**
 * @file screen.h
 * @brief Screen wrapper class
 */

#include <FL/Fl_Window.H>
#include <FL/Fl.H>
#include <FL/fl_draw.H>

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


private:

	Fl_Window* window;

};

}
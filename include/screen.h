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
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

/**
 * @file screen.h
 * @brief Screen wrapper class.
 */

namespace flab {

using std::vector;

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
	 * @param backgruond Background color
	 * @param title Title
	 * @return Is init successed
	 *   @retval If successed , return true
	*/
	bool init(int wide, int height, const char* title = "FoxLab view", Fl_Color background = RGBcol(255, 255, 255));

	/**
	 * @brief Set FPS.
	 * @param newfps New FPS value
	*/
	void fps(double newfps);
	/**
	 * @brief Get FPS.
	 * @return FPS value
	*/
	double fps();
	/**
	 * @brief Set background color.
	 * @param newcol New color
	*/
	void background(Fl_Color newcol);
	/**
	 * @brief Get backgruond color
	 * @return Color
	*/
	Fl_Color background();

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
	
private:

	static void redraw(void* args) {
		screen* w = (screen*)args;
		w->window->redraw();
		Fl::add_timeout(1 / w->redrawPerSec, redraw, args);
	}

	Fl_Double_Window* window;
	Fl_Box* bgbox;
	bool showed;

	double redrawPerSec;

};

}
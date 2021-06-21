#pragma once
#define DLLexport
#include "dllexport.h"
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <stdexcept>
#include <exception>

/**
 * @file widgetbase.h
 * @brief Base class for widgets.
 * If you want to create customize widgets , include this.
 */

namespace flab {

using std::out_of_range;
using std::invalid_argument;
using std::length_error;
using std::domain_error;

#define solid FL_SOLID
#define dash FL_DASH
#define dot FL_DOT

#define RGBcol fl_rgb_color

/**
 * @brief Virtual base class for user widget.
*/
DLLfrm class widgetbase :public Fl_Widget {
public:

	/**
	 * @brief Init widet
	 * @param x X coordinate
	 * @param y Y coordinate
	 * @param w Wide
	 * @param h Height
	 * @param label label of the widget
	*/
	widgetbase(int _x, int _y, int _w, int _h, const char* label = 0L);

	/**
	 * @brief update widget
	*/
	virtual void update();
	void draw();

protected:
	int x, y, w, h;

	/**
	 * @brief Draw a circle
	 * @param _x X coordinate
	 * @param _y Y coordinate
	 * @param _r Radius
	 * @param _col Color
	 * @param _wide Wide
	 * @param _style Style of the lines
	*/
	void circle(int _x, int _y, int _r, Fl_Color _col, int _wide, int _style);
	/**
	 * @brief Draw a filled circle
	 * @param _x X coordinate
	 * @param _y Y coordinate
	 * @param _r Radius
	 * @param _col Color
	*/
	void circle_fill(int _x, int _y, int _r, Fl_Color _col);
	/**
	 * @brief Draw a rectangle
	 * @param _x X coordinate
	 * @param _y Y coordinate
	 * @param _xw X wide
	 * @param _yw Y wide
	 * @param _col Color
	 * @param _wide Wide
	 * @param _style Style of the lines
	*/
	void rect(int _x, int _y, int _xw, int _yw, Fl_Color _col, int _wide, int _style);
	/**
	 * @brief Draw a filled rectangle
	 * @param _x X coordinate
	 * @param _y Y coordinate
	 * @param _xw Wide
	 * @param _yw Height
	 * @param _col Color
	*/
	void rect_fill(int _x, int _y, int _xw, int _yw, Fl_Color _col);
	/**
	 * @brief Draw a line.
	 * @param _x1 X1
	 * @param _y1 Y1
	 * @param _x2 X2
	 * @param _y2 Y2
	 * @param _col Color
	 * @param _wide Wide
	 * @param _style Style
	*/
	void line(int _x1, int _y1, int _x2, int _y2, Fl_Color _col, int _wide, int _style);
};

}
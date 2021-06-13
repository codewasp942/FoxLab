#pragma once
#define DLLexport
#include "dllexport.h"
#include <cmath>

/**
 * @file vector2D.h
 * @brief 2D vector class.
 */

namespace flab {

DLLfrm class vector2D {
public:
	vector2D();
	vector2D(double _x, double _y);

	vector2D operator+(const vector2D& b);
	vector2D operator-(const vector2D& b);
	vector2D operator*(const double& b);
	vector2D operator/(const double& b);

	void operator+=(const vector2D& b);
	void operator-=(const vector2D& b);

	double dis(const vector2D& b);
	
	double x, y;
};

#define zeroVector vector2D(0,0)

}
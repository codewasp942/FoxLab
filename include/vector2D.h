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

	double operator*(const vector2D& b);

	void operator+=(const vector2D& b);
	void operator-=(const vector2D& b);
	
	/**
	 * @brief Caculate distance to an another 2D vector.
	 * @param b The another vector
	 * @return distance
	*/
	double dis(const vector2D& b);
	/**
	 * @brief Get length.
	 * @return length
	*/
	double len();
	/**
	 * @brief Normalize vector.
	*/
	void normalize();
	/**
	 * @brief Get normalized vector.
	 * @return normalized vector
	*/
	vector2D normalized();
	
	double x, y;
};

#define zeroVector vector2D(0,0)

}
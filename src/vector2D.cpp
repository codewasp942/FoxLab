#include "vector2D.h"
using namespace flab;

vector2D::vector2D() :x(0), y(0) {}
vector2D::vector2D(double _x, double _y) : x(_x), y(_y) {}

vector2D vector2D::operator+(const vector2D& b) {
	return vector2D(x + b.x, y + b.y);
}

vector2D vector2D::operator-(const vector2D& b) {
	return vector2D(x - b.x, y - b.y);
}

vector2D vector2D::operator*(const double& b) {
	return vector2D(x * b, y * b);
}

vector2D vector2D::operator/(const double& b) {
	return vector2D(x / b, y / b);
}

double vector2D::operator*(const vector2D& b) {
	return x * b.x + y * b.y;
}

void vector2D::operator+=(const vector2D& b) {
	x += b.x; y += b.y;
}

void vector2D::operator-=(const vector2D& b) {
	x -= b.x; y -= b.y;
}

double vector2D::dis(const vector2D& b) {
	return std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
}

double vector2D::len() {
	return std::sqrt(x * x + y * y);
}

void vector2D::normalize() {
	register double d = dis(zeroVector);
	x /= d;
	y /= d;
}

vector2D vector2D::normalized() {
	register double d = dis(zeroVector);
	return vector2D(x / d, y / d);
}
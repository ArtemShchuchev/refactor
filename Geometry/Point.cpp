#include "Point.h"

Point::Point() : x(0), y(0), z(0)
{
}

Point::Point(const int _x, const int _y, const int _z) : x(_x), y(_y), z(_z)
{
}

Point::Point(const Point& P) : x(P.x), y(P.y), z(P.z)
{
}

void Point::setPoint(const int _x, const int _y, const int _z)
{
	x = _x;
	y = _y;
	z = _z;
}

void Point::shiftPoint(const int delta_x, const int delta_y, const int delta_z)
{
	x += delta_x;
	y += delta_y;
	z += delta_z;
}

void Point::scalePointX(const int scale)
{
	x *= scale;
}

void Point::scalePointY(const int scale)
{
	y *= scale;
}

void Point::scalePointZ(const int scale)
{
	z *= scale;
}

void Point::scalePoint(const int scale)
{
	if (scale == 0) return;
	x /= scale;
	y /= scale;
	z /= scale;
}

Point Point::getPoint()
{
	return *this;
}

int Point::getX()
{
	return this->x;
}
int Point::getY()
{
	return this->y;
}
int Point::getZ()
{
	return this->z;
}

const Point Point::absPoint(Point const& point)
{
	return Point(abs(point.x), abs(point.y), abs(point.z));
}

Point& Point::operator=(const Point& P)
{
	if (this == &P) return *this;

	x = P.x;
	y = P.y;
	z = P.z;
	return *this;
}

const Point operator-(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

const Point operator+(const Point& lhs, const Point& rhs)
{
	return Point(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}
#pragma once
#include <math.h>
class Point
{
private:
	int x, y, z;
public:
	Point();
	Point(const int _x, const int _y, const int _z = 0);
	Point(const Point&);
	//void setPoint(const int _x, const int _y, const int _z = 0);
	void shiftPoint(const int delta_x, const int delta_y, const int delta_z = 0);
	void scalePointX(const int scale);
	void scalePointY(const int scale);
	void scalePointZ(const int scale);
	void scalePoint(const int scale);
	Point getPoint();
	int getX();
	int getY();
	int getZ();
	const Point absPoint(Point const&);
	friend const Point operator- (const Point&, const Point&);
	friend const Point operator+ (const Point&, const Point&);
	Point& operator= (const Point&);
};


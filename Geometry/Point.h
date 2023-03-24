#pragma once
class Point
{
private:
	int x, y, z;
public:
	Point();
	Point(const int _x, const int _y, const int _z = 0);
	Point(const Point&);
	void setPoint(const int _x, const int _y, const int _z = 0);
	Point getPoint();
	int getX();
	int getY();
	int getZ();
	const Point abs(Point const&);
	friend const Point operator- (const Point&, const Point&);
	friend const Point operator+ (const Point&, const Point&);
	Point& operator= (const Point&);
};


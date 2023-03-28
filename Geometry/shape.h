#pragma once
#include<string>
#include "Point.h"
class Shape : public Point
{
protected:
	double volume;
	double square;
	Point* p;

private:
	int qtyPoint;

public:
	Shape(const int _qtyPoint);
	~Shape();
	Point* getPoints();
	double getVolume();
	double getSquare();
	virtual void shift(const int delta_x, const int delta_y, const int delta_z = 0);
	virtual void scaleX(const int sc);
	virtual void scaleY(const int sc);
	virtual void scaleZ(const int sc);
	virtual void scale(const int sc);
};

/*
class Shape
{
public:
	static const int line = 0;
	static const int sqr = 1;
	static const int cube = 2;
	static const int circle = 3;
	static const int cylinder = 4;
	Shape() = default;
	Shape(int type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8);
	Shape(int type, int _x1, int _y1, double R, double H);
	int getType() { return type; }

	int type;
	int x1 = 0, y1 = 0, z1 = 0,
		x2 = 0, y2 = 0, z2 = 0,
		x3 = 0, y3 = 0, z3 = 0,
		x4 = 0, y4 = 0, z4 = 0,
		x5 = 0, y5 = 0, z5 = 0,
		x6 = 0, y6 = 0, z6 = 0,
		x7 = 0, y7 = 0, z7 = 0,
		x8 = 0, y8 = 0, z8 = 0;
	double volume;
	double square;
	double height;
	double radius;
};
*/

class Line : public Shape
{
private:
	static const int qtyPoint;

public:
	Line(Point P1, Point P2);
};

class Square : public Shape
{
private:
	static const int qtyPoint;

public:
	Square(Point P1, Point P2, Point P3, Point P4);
};

class Cube : public Shape
{
private:
	static const int qtyPoint;

public:
	Cube(Point P1, Point P2, Point P3, Point P4, Point P5, Point P6, Point P7, Point P8);
};

class Circle : public Shape
{
private:
	static const int qtyPoint;
	double radius;

public:
	Circle(Point P, double R);
	void shift(const int delta_x, const int delta_y, const int delta_z = 0) override;
	void scaleX(const int) override;
	void scaleY(const int) override;
	void scaleZ(const int) override;
	void scale(const int) override;
};

class Cylinder : public Shape
{
private:
	static const int qtyPoint;
	double height;
	double radius;

public:
	Cylinder(Point P, double R, double H);
	void shift(const int delta_x, const int delta_y, const int delta_z = 0) override;
	void scaleX(const int) override;
	void scaleY(const int) override;
	void scaleZ(const int) override;
	void scale(const int) override;
};


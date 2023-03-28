#define _USE_MATH_DEFINES
#include"shape.h"

Shape::Shape(const int _qtyPoint) : qtyPoint(_qtyPoint), volume(0.0), square(0.0)
{
	p = (qtyPoint <= 0) ? nullptr : new Point[qtyPoint];
}

Shape::~Shape()
{
	if (p) delete[] p;
}

Point* Shape::getPoints()
{
	return p;
}

double Shape::getVolume()
{
	return volume;
}

double Shape::getSquare()
{
	return square;
}

void Shape::shift(const int delta_x, const int delta_y, const int delta_z)
{
	for (int i(0); i< qtyPoint; ++i)
		p[i].shiftPoint(delta_x, delta_y, delta_z);
}

void Shape::scaleX(const int sc)
{
	for (int i(0); i < qtyPoint; ++i)
		p[i].scalePointX(sc);
}
void Shape::scaleY(const int sc)
{
	for (int i(0); i < qtyPoint; ++i)
		p[i].scalePointY(sc);
}
void Shape::scaleZ(const int sc)
{
	for (int i(0); i < qtyPoint; ++i)
		p[i].scalePointZ(sc);
}
void Shape::scale(const int sc)
{
	for (int i(0); i < qtyPoint; ++i)
		p[i].scalePoint(sc);
}

/*
#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>
Shape::Shape(int _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
{
	type = _type;
	// заполняем координаты фигуры
	switch (type)
	{
	case line:
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		break;
	case sqr:
		x1 = _x1; y1 = _y1;
		x2 = _x2; y2 = _y2;
		x3 = _x3; y3 = _y3;
		x4 = _x4; y4 = _y4;
		break;
	case cube:
		x1 = _x1; y1 = _y1; z1 = _z1;
		x2 = _x2; y2 = _y2; z2 = _z2;
		x3 = _x3; y3 = _y3; z3 = _z3;
		x4 = _x4; y4 = _y4; z4 = _z4;
		x5 = _x5; y5 = _y5; z5 = _z5;
		x6 = _x6; y6 = _y6; z6 = _z6;
		x7 = _x7; y7 = _y7; z7 = _z7;
		x8 = _x8; y8 = _y8; z8 = _z8;
		break;
	default:
		break;
	}

	// Считаем площадь фигуры
	// стороны фигуры
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	switch (type)
	{
	case line:
		square = 0;
		break;
	case sqr:
		square = a * b;
		break;
	case cube:
		square = 2 * a * b + 2 * a * c + 2 * b * c;
		break;
	default:
		break;
	}

	// Считаем объем фигуры
	// стороны фигуры
	switch (type)
	{
	case line:
		volume = 0;
		break;
	case sqr:
		volume = 0;
		break;
	case cube:
		volume = a * b * c;
		break;
	default:
		break;
	}

}

Shape::Shape(int type, int _x1, int _y1, double R, double H)
{
	// заполняем координаты фигуры
	switch (type)
	{
	case circle:
		x1 = _x1; y1 = _y1;
		radius = R;
		break;
	case cylinder:
		x1 = _x1; y1 = _y1;
		radius = R;
		height = H;
		break;
	default:
		break;
	}

	// Считаем площадь фигуры
	// стороны фигуры

	switch (type)
	{
	case circle:
		square = M_PI * R * R;
		break;
	case cylinder:
		square = M_PI * R * R + 2 * R * height;
		break;
	default:
		break;
	}

	// Считаем объем фигуры
	// стороны фигуры
	switch (type)
	{
	case line:
		volume = 0;
		break;
	case sqr:
		volume = 0;
		break;
	case cube:
		volume = M_PI * R * R * height;
		break;
	default:
		break;
	}

}
*/

/////////////////////////////////////////////
const int Line::qtyPoint = 2;

Line::Line(Point P1, Point P2) : Shape(qtyPoint)
{
	p[0] = P1;
	p[1] = P2;
}

/////////////////////////////////////////////
const int Square::qtyPoint = 4;

Square::Square(Point P1, Point P2, Point P3, Point P4) : Shape(qtyPoint)
{
	p[0] = P1;
	p[1] = P2;
	p[2] = P3;
	p[3] = P4;
	Point difr(Point::absPoint(p[0] - p[1]));// Чушь! С чего решили, что точки на диагонали?
	square = difr.getX() * difr.getY();
}

/////////////////////////////////////////////
const int Cube::qtyPoint = 8;

Cube::Cube(Point P1, Point P2, Point P3, Point P4, Point P5, Point P6, Point P7, Point P8) : Shape(qtyPoint)
{
	p[0] = P1;
	p[1] = P2;
	p[2] = P3;
	p[3] = P4;
	p[4] = P5;
	p[5] = P6;
	p[6] = P7;
	p[7] = P8;
	Point difr(Point::absPoint(p[0] - p[1]));// Чушь! С чего решили, что точки на диагонали?
	square = 2 * difr.getX() * difr.getY() + 2 * difr.getX() * difr.getZ() + 2 * difr.getY() * difr.getZ();
	volume = difr.getX() * difr.getY() * difr.getZ();
}

/////////////////////////////////////////////
const int Circle::qtyPoint = 1;

void Circle::shift(const int delta_x, const int delta_y, const int delta_z)
{
	return;
}

Circle::Circle(Point P, double R) : radius(R), Shape(qtyPoint)
{
	p[0] = P;
	square = M_PI * radius * radius;
}

void Circle::scaleX(const int sc)
{
	return;
}

void Circle::scaleY(const int sc)
{
	return;
}

void Circle::scaleZ(const int sc)
{
	return;
}

void Circle::scale(const int)
{
	return;
}

/////////////////////////////////////////////
const int Cylinder::qtyPoint = 1;

void Cylinder::shift(const int delta_x, const int delta_y, const int delta_z)
{
	return;
}

Cylinder::Cylinder(Point P, double R, double H) : radius(R), height(H), Shape(qtyPoint)
{
	p[0] = P;
	square = 2 * M_PI * radius * (height + radius);
	volume = M_PI * radius * radius * height;
}

void Cylinder::scaleX(const int)
{
	return;
}

void Cylinder::scaleY(const int)
{
	return;
}

void Cylinder::scaleZ(const int)
{
	return;
}

void Cylinder::scale(const int)
{
	return;
}

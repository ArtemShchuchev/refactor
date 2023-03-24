#define _USE_MATH_DEFINES
#include"shape.h"
#include<cmath>
Shape::Shape(int _type, Point P1, Point P2, Point P3, Point P4, Point P5, Point P6, Point P7, Point P8)
{
	type = _type;
	// заполняем координаты фигуры
	switch (type)
	{
	case line: 
		p[0] = P1;
		p[1] = P2;
		break;
	case sqr:
		p[0] = P1;
		p[1] = P2;
		p[2] = P3;
		p[3] = P4;
		break;
	case cube:
		p[0] = P1;
		p[1] = P2;
		p[2] = P3;
		p[3] = P4;
		p[4] = P5;
		p[5] = P6;
		p[6] = P7;
		p[7] = P8;
		break;
	default:
		break;
	}

	// Считаем площадь фигуры
	// стороны фигуры
	Point difr(Point::abs(P1 - P2));
	switch (type)
	{
	case line:
		square = 0;
		break;
	case sqr:
		square = difr.getX() * difr.getY();
		break;
	case cube:
		square = 2 * difr.getX() * difr.getY() + 2 * difr.getX() * difr.getZ() + 2 * difr.getY() * difr.getZ();
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
		volume = difr.getX() * difr.getY() * difr.getZ();
		break;
	default:
		break;
	}

}

Shape::Shape(int type, Point P, double R, double H)
{
	// заполняем координаты фигуры
	switch (type)
	{
	case circle:
		p[0] = P;
		radius = R;
		break;
	case cylinder:
		p[0] = P;
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
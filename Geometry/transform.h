﻿#pragma once
#include"shape.h"
class transform
{
public:
	transform(Shape* const);
	Shape* shift(int, int, int);
	Shape scaleX(int);
	Shape scaleY(int);
	Shape scaleZ(int);
	Shape scale(int);

private:
	Shape* shape;
};

/*
#include"shape.h"
class transform
{
public:
	transform(const Shape& sh);
	Shape shift(int m, int n, int k);
	Shape scaleX(int a);
	Shape scaleY(int d);
	Shape scaleZ(int e);
	Shape scale(int s);

private:
	Shape shape;
};
*/

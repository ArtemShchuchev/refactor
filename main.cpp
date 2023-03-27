#include "SecondaryFunction.h"
#include "shape.h"
#include "transform.h"

/*
Задание 1
«Геометрические фигуры»

Представлен класс, описывающий геометрические фигуры:
- линия
- прямоугольник
- параллелепипед

И класс, описывающий геометрические преобразования фигур:
- смещения по осям x,y,z
- масштабирование по отдельным осям
- полное масштабирование

Необходимо выделить из кода «плохие запахи» и провести
рефакторинг кода, приведя его к корректному виду.
*/

int main(int argc, char** argv)
{
	printHeader(L"Геометрические фигуры");

	Shape* shapePtr = nullptr;

	shapePtr = new Line({ 20, 30 }, { 10, 15 });
	std::wcout << "Line\n"
		<< L"Объём:   " << shapePtr->getVolume() << "\n"
		<< L"Площадь: " << shapePtr->getSquare() << "\n\n";
	
	//Line ln({ 20, 30 }, { 10, 15 });
	//transform tr(&ln);
	//Shape* ptr = tr.shift(100, 100, 10);
	//shapePtr->shift(10, 10, 10);
	//Point pl1 = ln.getPoint_1(), pl2 = ln.getPoint_2();
	Point* pl = shapePtr->getPoint();
	std::wcout << "Point_1: " << pl[0].getX() << ", " << pl[0].getY() << ", " << pl[0].getZ() << "\n";
	std::wcout << "Point_2: " << pl[1].getX() << ", " << pl[1].getY() << ", " << pl[1].getZ() << "\n\n";


	Point ps1(0, 0), ps2(10, 10), ps3(10, 0), ps4(0, 10);
	shapePtr = new Square(ps1, ps2, ps3, ps4);
	std::wcout << "Square\n"
		<< L"Объём:   " << shapePtr->getVolume() << "\n"
		<< L"Площадь: " << shapePtr->getSquare() << "\n\n";

	Point pc1(0, 0, 0), pc2(10, 10, 10), pc3(10, 0, 0), pc4(0, 10, 0),
		pc5(0, 0, 10), pc6(10, 10, 0), pc7(10, 0, 10), pc8(0, 10, 10);
	shapePtr = new Cube(pc1, pc2, pc3, pc4, pc5, pc6, pc7, pc8);
	std::wcout << "Cube\n"
		<< L"Объём:   " << shapePtr->getVolume() << "\n"
		<< L"Площадь: " << shapePtr->getSquare() << "\n\n";

	shapePtr = new Circle({ 0,0 }, 10);
	std::wcout << "Circle\n"
		<< L"Объём:   " << shapePtr->getVolume() << "\n"
		<< L"Площадь: " << shapePtr->getSquare() << "\n\n";

	shapePtr = new Cylinder({ 0,0 }, 10, 20);
	std::wcout << "Cylinder\n"
		<< L"Объём:   " << shapePtr->getVolume() << "\n"
		<< L"Площадь: " << shapePtr->getSquare() << "\n\n";

	return 0;
}

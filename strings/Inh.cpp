#include <iostream>
#include "Inh.h"

Square::Square() :side(0) {}
Square::Square(int side):side(side) {}
double Square::area() {
		return side * side;
	}



Triangle::Triangle() :base(0), height(0) {}
Triangle::Triangle(int base, int height) :base(base), height(height) {};
double Triangle::area() {
		return 0.5 * base * height;
	}


Circle::Circle() :r(0) {}
Circle::Circle(int r) :r(r) {}
double Circle::area() {
		return 3.14159 * r * r;
	}

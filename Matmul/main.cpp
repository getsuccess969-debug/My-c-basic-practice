#include <iostream>
#include "matrix.h"
int main() {
	matrix mat;
	matrix bot = mat;
	mat.display();
	mat.guassel();
	mat.display();
	bot.display();
	matrix hat;
	matrix cot = std::move(hat);
	cot.display();
	hat.display();
	cot.guassel();
	cot.display();
}
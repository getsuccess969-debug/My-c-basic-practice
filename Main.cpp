#include <iostream>
#include "Integer.h"
Integer operator+(const Integer& lhs, const Integer& rhs) {
	return Integer(*lhs.ptr + *rhs.ptr);
}

Integer operator+(const Integer& lhs, int rhs) {
	return Integer(*lhs.ptr + rhs);
}

Integer operator+(int lhs, const Integer& rhs) {
	return Integer(lhs + *rhs.ptr);
}
int main() {
	Integer i(3), j(4);
	auto k = j+8;
	Integer l(j + k+8);
	std::cout << l.get();
}
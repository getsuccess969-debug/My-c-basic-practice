#include <iostream>
#include "Integer.h"
#include <memory>
Integer operator+(const Integer& lhs, const Integer& rhs) {
	return Integer(*lhs.ptr + *rhs.ptr);
}

Integer operator+(const Integer& lhs, int rhs) {
	return Integer(*lhs.ptr + rhs);
}

Integer operator+(int lhs, const Integer& rhs) {
	return Integer(lhs + *rhs.ptr);
}
std::ostream &operator<<(std::ostream& out, Integer& x) {
	out << x.get();
	return out;
}
std::istream& operator>>(std::istream &in, Integer& a) {
	int x;
	in >> x;
	a.set(x);
	return in;
}
int main() {
	Integer i(3), j(4);
	auto k = i + j + 10;
	k();
	k(0);

}

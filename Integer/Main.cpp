#include <iostream>
#include "Integer.h"
Integer Add(Integer& a, Integer& b) {
	Integer temp;
	temp.set_val(a.get() + b.get());
	return temp;
}
int main() {
	Integer i(5);
	Integer b;
	b = i;
	auto c{ std::move(Add(i,b)) };
	i.set_val(10);
	std::cout << "i:" << i.get() << "\nc:" <<c.get() << "\n";
	return 0;
}
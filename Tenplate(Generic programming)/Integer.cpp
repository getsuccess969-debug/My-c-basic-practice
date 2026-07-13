#include <iostream>
#include "Integer.h"
Integer::Integer() :Integer(0) {}
Integer::Integer(int i) {
	ptr = new int(i);
}

Integer::Integer(const Integer& i) {
	ptr = new int(*i.ptr);
	std::cout << "Integer(copy...)\n";
}
Integer::Integer(Integer&& i) {
	if (i.ptr != nullptr) {
		ptr = i.ptr;
		i.ptr = nullptr;
		std::cout << "moved!\n";
	}
	else {
		std::cout << "ptr is nullptr!\n";
		ptr = new int(0);
	}
}
Integer& Integer::operator=(Integer i) {
	// Swap the guts of 'this' with the temporary 'i'
	std::swap(this->ptr, i.ptr);
	return *this; // Enables chaining
}

void Integer::operator=(Integer&& i) {
	if (this == &i) { return; }
	if (i.ptr == nullptr) { return; }
	if (ptr != nullptr) { delete ptr; }
	ptr = i.ptr;
	i.ptr = nullptr;




}


void Integer::set_val(int i) {
	if (ptr == nullptr) { ptr = new int(); }
	*ptr = i;
}
Integer Integer::operator+(int a)const
{
	return Integer(*this->ptr + a);
}
Integer::~Integer() {
	delete ptr;
	std::cout << "Destruct\n";
}

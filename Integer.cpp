#include <iostream>
#include "Integer.h"

Integer::Integer() { ptr = new int(0); }
Integer::Integer(int x) { ptr = new int(x); }
Integer::Integer(Integer &x) {
	if (x.ptr == nullptr) { ptr = nullptr; }//prevent assigning nullptr
	else{
	ptr = new int(*x.ptr);//deep copy
	}
}
Integer::Integer(Integer &&x) { 
	if (x.ptr == nullptr) { ptr = nullptr; }//prevent assigning nullptr
	else {
		ptr = x.ptr;
		x.ptr = nullptr;
	}
}
Integer::~Integer() { delete ptr; }
Integer Integer::operator=(Integer& x) {
	if (this == &x) { return *this; }//prevent self assignment
	if (x.ptr == nullptr) { ptr = nullptr; }//prevent assigning nullptr
	else {
		delete ptr;//delete old ptr for safety reasons such as size incompatibility in larger objects ,eg.matrices

		ptr = new int(0);
		*ptr = *x.ptr;
		return *this;
	}
}
Integer Integer::operator=(Integer&& x) {
	if (this == &x) {return *this; }
	if (x.ptr == nullptr) { ptr = nullptr; }
	else {
		delete ptr;//deleting old ptr value for safety concerns
		ptr = x.ptr;
		x.ptr = nullptr;
		return *this;
	}
}
Integer	Integer::operator+(Integer& b) {
	if (b.ptr == nullptr) { return *this; }
	if (ptr == nullptr) { return *this; }
	Integer temp;
	*temp.ptr = *ptr + *b.ptr;
	return temp;
}
int Integer :: get() const{
	return *ptr;
}
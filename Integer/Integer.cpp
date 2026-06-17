#include <iostream>
#include "Integer.h"
Integer::Integer():Integer(0){}
Integer::Integer(int i) {
	ptr = new int(i);
}

Integer::Integer(Integer& i) {
	if (this == &i) { return; }
	ptr = new int(*i.ptr);
	
	
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
void Integer::operator=(Integer& i){
	if (this == &i) { return; }
	if (i.ptr == nullptr) { return; }
	{
		if (ptr == nullptr) { ptr = new int(*i.ptr); }
		else {
			*ptr = *i.ptr;
		}
	}

}

void Integer::operator=(Integer&& i) {
	if (this == &i) { return;}
	if (i.ptr == nullptr) { return; }
	if (ptr != nullptr) { delete ptr; }
	ptr = i.ptr;
	i.ptr = nullptr;

	


}


void Integer::set_val(int i) {
	if (ptr == nullptr) { ptr = new int(); }
	*ptr = i;
}
Integer::~Integer() {
	delete ptr;
}

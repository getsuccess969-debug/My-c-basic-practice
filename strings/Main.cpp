#include <iostream>
#include <sstream>
#include <vector>
#include "Inh.h"
std::ostream& operator<< (std::ostream &out,std::stringstream &s) {
	std::string a= s.str();
	out << a;
	return out;
}
std::vector<int> extract(std::string a) {
	std::vector<int> vec;
	std::stringstream ss;
	ss.str(a);
	int ai;
	while (!ss.fail()) {
		ss >> ai;
		
		vec.push_back(ai);
	}
	return vec;
}
void display(std::vector<int> i) {
	for (int j : i) {
		std::cout << j << "\b\n";
	}

}
int main() {
	shape* s[] = {
		new Square(2),
		new Triangle(2,3),
		new Circle(10),
		new Square(),
		new Triangle(3,3)
	};
	
	for (int i = 0;i < 5;i++) {
		std::cout << "area:" << s[i]->area()<<"\n";
	}
}
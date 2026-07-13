#include <iostream>
#include "Integer.h"
#include <string>
std::ostream& operator<<(std::ostream& out, const Integer& I) {
	if (I.ptr != nullptr) {
		out << *I.ptr;
	}
	else {
		out << "null";
	}
	return out;
}
// Template non-member operator+
// We use 'T' for the primitive type to keep it generic
template <typename T>
Integer operator+(const Integer& lhs, T rhs) {
	// We access the internal value and add the primitive
	// This assumes you have a way to get the value, or make this a friend
	return Integer(*(lhs.ptr) + static_cast<int>(rhs));
}

// Symmetric version to allow (int + Integer)
template <typename T>
Integer operator+(T lhs, const Integer& rhs) {
	return Integer(static_cast<int>(lhs) + *(rhs.ptr));
}
/*template<typename T>
void tem(T a, T b) {
	std::cout << "type of a:" << typeid(a).name() << " Type of b:" << typeid(b).name() << "\n";
}

template<typename c>
c max(c a, c b) {
	return a > b ? a : b;
}
template char max(char x, char y);//explicit instantiation
template<> const char* max<const char*>(const char* a, const char* b) {//explicit specialisation
	return strcmp(a, b) > 0 ? a : b;
}
template<int size>
void print() {
	char c[size];
	std::cout<<size<<"\n";
}
/*template<typename T>
T sum(T* parr, int size) {
	T sum{};
	for(int i = 0;i < size;i++) {
		sum += parr[i];
	} 
	return sum;
}*/
/*template<typename T, int size>
T sum(T(&arr)[size]) {
	T sum{};
	for (int i = 0;i < size;i++)
	{
		sum += arr[i];

	} return sum;
}*/




class Employee {
	std::string m_name;
	Integer m_Id;
public:
	template<typename T1, typename T2>
	Employee(T1&& name, T2&& Id)
		: m_name(std::forward<T1>(name)),
		m_Id(std::forward<T2>(Id))
	{
	}
};




template<typename T1,typename T2>
auto sum(T1 a, T2 b) {
	return a + b;
}

template<typename T1,typename T2>
Employee* create(T1&& a, T2&& b) {
	return new Employee(std::forward<T1>(a), std::forward<T2>(b));
}
int main() {
	/*rint<3>();
	std::cout << "Max:" << max(2, 3)<<"\n";
	std::cout << "Max:" << max(4, 3) << "\n";
	std::cout << "Max:" << max<double>(4.0, 3) << "\n";
	std::cout << "Max:" << max("aarush", "arush") << "\n";
	*/
	auto emp = create("hegg", Integer{ 69 });
std::cout<<"sum:"<< sum(static_cast<Integer>(1), 10.0)<<"\n";
}
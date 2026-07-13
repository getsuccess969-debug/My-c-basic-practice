#pragma once
class Integer {
	int* ptr;
public:
	Integer();
	Integer(int i);
	Integer(const Integer& i);
	Integer(Integer&& i);
	~Integer();
	Integer& operator=(Integer i);
	void operator=(Integer&& i);
	int get() {
		return *ptr;
	}
	void set_val(int i);
	Integer operator+(int a)const;
	friend std::ostream& operator<<(std::ostream& out, const Integer& I);
	template <typename T>
	friend Integer operator+(const Integer& lhs, T rhs);

	template <typename T>
	friend Integer operator+(T lhs, const Integer& rhs);
};
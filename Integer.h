#pragma once
class Integer {
	int* ptr;
public:
	Integer();
	Integer(int x);
	Integer(Integer &x);//l value copy
	Integer(Integer &&X);//rvalue move
	~Integer();
	Integer operator=(Integer& x);
	Integer operator=(Integer&& x);
	Integer operator+(Integer &b);
	friend Integer operator+(const Integer& lhs, const Integer& rhs);
	friend Integer operator+(const Integer& lhs, int rhs);
	friend Integer operator+(int lhs, const Integer& rhs);
	int get() const;
};
#pragma once
class shape {
public:
	virtual double area()=0;
};
class Square :public shape {
	int side;
public:
	Square();
	Square(int side);
	double area();
	~Square();
};
class Triangle :public shape {
	int base ,height;
public:
	Triangle();
	Triangle(int base,int height);
	double area();
};
class Circle:public shape {
	int r;
public:
	Circle();
	Circle(int r);
	double area();
};
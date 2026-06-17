#pragma once
class Car {
	static int count;
	int passengers;
	double fuel, speed;
public:
	Car();
	Car(int fuel);
	Car(int fuel, int passengers);
	~Car();
	void display();
	void accelerate();
	void brake();
	void add_pass(int p);
};
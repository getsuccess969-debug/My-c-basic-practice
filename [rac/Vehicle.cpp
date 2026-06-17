#include <iostream>
#include "vehicle.h"
Car::Car() :Car(0, 0) { std::cout << "Car(0,0)\n"; }
Car::Car(int fuel) :Car(fuel, 0) { std::cout << "Car(f,0)\n"; }
Car::Car(int f, int p) :fuel(f),passengers(p){ std::cout << "Car(f,p)\n"; }
Car::~Car() {}
void Car::accelerate() {
	if (fuel >= speed*0.05+0.5) {
		speed += 4;
		fuel -= 0.5;
	}
}
void Car::brake() {
	if (speed >= 1) {
		speed -= 0.5 / (speed + 0.5);
	}
	else {
		speed = 0;
	}

}
void Car::display() {
	std::cout << "Speed:" << speed << "\nFuel:" << fuel << "\npassengers:" << passengers << "\n";
}
void Car::add_pass(int p) {
	if (passengers+p <= 5) {
		passengers += p;
	}
	else {
		std::cout << "Max passengers:5,,so only " << 5 - passengers << " more can be accomodated\n";
	}
}
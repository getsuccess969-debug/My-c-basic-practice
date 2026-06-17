#include <iostream>
#include "vehicle.h"	
namespace funcs{
			void incr(int& x) {
				x = x + 1;
				std::cout << "int& x\n";
			}
			void incr(int* x) {
				*x = *x + 1;
				std::cout << "int* x\n";
			}
			int square(int x) {
				return x * x;
			}
			int cube(int x) {
				return x * x;
			}
			int expo(int x) {
				return exp(x);

			}
			int cosi(int x) {
				return cos(x);
			}
		}
namespace prac{
			class mat {
				int* ptr;
				int row, col;
			public:
				mat() {
					using namespace std;
					cout << "Enter row and coloumn\n";
					cin >> row >> col;
					ptr = new int[row * col];
					for (int i = 0;i < row;i++) {
						for (int j = 0;j < col;j++) {
							ptr[col * i + j] = j;
						}
					}


				}
				mat(mat&& v) : ptr(v.ptr), row(v.row), col(v.col) { // Copy the dimensions!
					v.ptr = nullptr;
					v.row = 0; // Reset source dimensions for safety
					v.col = 0;
					std::cout << "moved\n";
				}
				mat(const mat& v) : row(v.row), col(v.col) { // Correctly copy the dimensions first
					ptr = new int[row * col];
					for (int i = 0; i < row * col; i++) {
						ptr[i] = v.ptr[i]; // Direct copy is faster than nested loops
					}
				}
				mat& operator=(const mat& v) {
					if (this != &v) { // Avoid self-assignment
						delete[] ptr;     // Clean up existing memory
						ptr = new int[v.row*v.col];
						for (int i = 0; i < v.row*v.col; ++i) ptr[i] = v.ptr[i];
					}
					std::cout << "move\n";
					row = v.row;
					col = v.col;
					return *this;
				}
				int get_row() {
					return row;
				}
				int get_col() {
					return col;
				}
				void display() {
					for (int i = 0;i < row;i++) {
						for (int j = 0;j < col;j++) {
							std::cout << " " << ptr[col * i + j];
						}
						std::cout << "\n";
					}
				}
			};
			class vec {
				int* ptr;
				static const int size = 3;
			public:
				vec() {
					ptr = new int[size];
					std::cin >> ptr[0] >> ptr[1] >> ptr[2];
				}
				vec(vec& v) {
					ptr = new int[size];
					int* pt = v.ptr;
					ptr[1] = pt[1];
					ptr[0] = pt[0];
					ptr[2] = pt[2];
				}
				vec(vec&& v) {
					ptr = v.ptr;
					v.ptr = nullptr;
					std::cout << "moved\n";
				}
				vec& operator=(const vec& other) {
					if (this != &other) { // Avoid self-assignment
						delete[] ptr;     // Clean up existing memory
						ptr = new int[size];
						for (int i = 0; i < size; ++i) ptr[i] = other.ptr[i];
					}
					return *this;
				}
				int* get_ptr() {
					return ptr;
				}
				void display() {
					std::cout << ptr[0] << "\n" << ptr[1] << "\n" << ptr[2] << "\n";
				}
				~vec() {
					delete[]ptr;
				}

			};
		}
namespace shapes{
			class shape {
			public:
				virtual double area() = 0;
			};
			class squar :public shape {
				double side;
			public:
				squar(double s) :side(s) {}
				double area() {
					return side * side;
				}
			};
			class triangle :public shape {
				double h, b;
			public:
				triangle(double b, double h) :b(b), h(h) {}
				double area() {
					return 0.5 * b * h;
				}
			};
			class circle :public shape {
				double r;
			public:
				circle(double r) :r(r) {}
				double area() {
					return 3.14159 * r * r;
				}
			};
		}


int main() {
	
		/*using namespace shapes;
				shape* s[] = {
				new triangle(5, 4),
				new circle(3),
				new squar(10),
				new triangle(10,10),
				new circle(12)
				};

				// Loop through the array to calculate areas
				for (int i = 0; i < 5; ++i) {
					std::cout << "Area " << i << ": " << s[i]->area() << std::endl;
				}
		
			}
			int x = 11;
			{
				using namespace funcs;
				incr(x);
				incr(&x);
				std::cout << cosi(x);

			}
			{
				using namespace prac;
				mat m;
				m.display();
				vec v;
				v.display();
				vec v2(v);
				vec v3 = v;
				v3.display();
				v2.display();
	
			}
			prac::vec v;
			auto v8{ std::move(v) };
			v8.display();*/
		/*prac::mat m;
				auto b = m;
				b.display();*/
	Car b(2);
	std::cout << "enter number of passengers you want to add:";
	int pass;
	std::cin >> pass;
	Car c(40,4);
	c.add_pass(pass);
	return 0;
}

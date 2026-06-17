#include <iostream>
#include "matrix.h"
matrix::matrix(int r, int c) :row(r),col(c){ ptr = new double[r * c];for (int i = 0;i < r * c;i++) { ptr[i] = 0; } }
matrix::matrix(){
	std::cout << "enter row and columns::";
	std::cin >> row >> col;
	ptr = new double[row * col];
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			ptr[i * col + j] = rand()/100;
		}
	}
}
matrix matrix::matmul(matrix &mat)
{
	
	if (mat.row != col) {
		std::cout << "incompatible!\n";
		matrix temp(1,1);
		return temp;
	}
	matrix temp(row, mat.col);
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < mat.col;j++) {
			for (int k = 0;k < mat.row;k++) {
				temp.ptr[i * mat.col + j] += this->ptr[i * col + k] * mat.ptr[k * mat.col + j];	
			}
		}
	}


	return temp;
}
void matrix::guassel()
{
	for (int i = 0; i < row - 1; i++) {
		// --- Swapping Technique ---
		if (std::abs(ptr[i * col + i]) < 1e-12) {
			for (int r = i + 1; r < row; r++) {
				if (std::abs(ptr[r * col + i]) > 1e-12) {
					for (int k = 0; k < col; k++) {
						double temp = ptr[i * col + k];
						ptr[i * col + k] = ptr[r * col + k];
						ptr[r * col + k] = temp;
					}
					break;
				}
			}
		}

		// --- Elimination Technique ---
		if (std::abs(ptr[i * col + i]) > 1e-12) {
			for (int j = i + 1; j < row; j++) {
				double l = ptr[j * col + i] / ptr[i * col + i];
				// Keep all precision here!
				for (int k = i; k < col; k++) {
					ptr[j * col + k] -= ptr[i * col + k] * l;
				}
			}
		}
	}
	
}
void matrix::display() {
	for (int i = 0;i < row;i++) {
		for (int j = 0;j < col;j++) {
			std::cout << " " << ptr[i * col + j];
		}
		std::cout<< "\n";
	}
}
matrix::~matrix()
{
	delete[] ptr;
}
matrix::matrix(matrix& mat) :row(mat.row), col(mat.col) {//copy constructor
	ptr = new double[row * col];
	for (int i = 0;i < row * col;i++) { ptr[i] = mat.ptr[i]; }

}
matrix::matrix(matrix&& mat) :ptr(mat.ptr), row(mat.row), col(mat.col) {//move constructor
	mat.ptr = nullptr;
	mat.row = 0;
	mat.col = 0;
	std::cout << "moved\n";
}
// Copy Assignment
matrix& matrix::operator=(const matrix& mat) {
	if (this != &mat) { // Prevent self-assignment
		delete[] ptr;    // Clean up existing memory
		row = mat.row;
		col = mat.col;
		ptr = new double[row * col];
		for (int i = 0; i < row * col; i++) ptr[i] = mat.ptr[i];
	}
	return *this;
}

// Move Assignment
matrix& matrix::operator=(matrix&& mat) noexcept {
	if (this != &mat) {
		delete[] ptr;
		ptr = mat.ptr;
		row = mat.row;
		col = mat.col;
		mat.ptr = nullptr; // Leave mat in a safe state
	}
	return *this;
}

#pragma once
class matrix {
	double* ptr = nullptr;
	int row, col;
public:
	matrix();
	matrix(int row, int col);
	matrix(matrix& mat);
	matrix(matrix&& mat);
	matrix& operator=(const matrix& mat); // Corrected
	matrix& operator=(matrix&& mat) noexcept;

	matrix matmul(matrix &mat);
	void guassel();
	void display();
	~matrix();
};
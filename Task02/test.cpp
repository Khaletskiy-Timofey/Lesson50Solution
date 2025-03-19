#include "test.h"

// wrong size
void test01() {
	int n = -3;
	int expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, expected, "test01");
}

// wrong size
void test02() {
	int n = 0;
	int expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, expected, "test02");
}

// matrix == null 
void test03() {
	int n = 3;
	int expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, expected, "test03");
}

// matrix with only one element
void test04() {
	int n = 1;
	int expected = 7;

	int** matrix = new int* [n];
	matrix[0] = new int[n] {7};

	print_test(matrix, n, expected, "test04");

	delete[] matrix[0];
	delete[] matrix;
}

// matrix 2x2 with all positive elements
void test05() {
	int n = 2;
	int expected = 18;

	int** matrix = new int* [n];
	matrix[0] = new int[n] {1, 2};
	matrix[1] = new int[n] {7, 8};

	print_test(matrix, n, expected, "test05");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix 2x2 with all negative elements
void test06() {
	int n = 2;
	int expected = -18;

	int** matrix = new int* [n];
	matrix[0] = new int[n] {-1, -2};
	matrix[1] = new int[n] {-7, -8};

	print_test(matrix, n, expected, "test06");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix 3x3 with positive and some zero elements
void test07() {
	int n = 3;
	int expected = 25;

	int** matrix = new int* [n];
	matrix[0] = new int[n] {1, 2, 3};
	matrix[1] = new int[n] {4, 5, 6};
	matrix[2] = new int[n] {7, 8, 9};

	print_test(matrix, n, expected, "test07");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix 5x5 with negative and some zero elements
void test08() {
	int n = 5;
	int expected = 36;

	int** matrix = new int* [n];

	for (int i = 0; i < n; ++i) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = i + j;
		}
	}

	print_test(matrix, n, expected, "test08");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with all zero elements
void test09() {
	int n = 3;
	int expected = 0;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n] {0, 0, 0};
	}

	print_test(matrix, n, expected, "test09");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// identity matrix 4x4 
void test10() {
	int n = 4;
	int expected = 8;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n] {1, 1, 1, 1};
	}

	print_test(matrix, n, expected, "test10");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// identity matrix 3x3 
void test11() {
	int n = 3;
	int expected = 5;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n] {1, 1, 1};
	}

	print_test(matrix, n, expected, "test11");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}
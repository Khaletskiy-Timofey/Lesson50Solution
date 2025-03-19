#include "test.h"

// wrong size
void test01() {
	int n = -3, m = 3;
	double expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, m, expected, "test01");
}

// wrong size
void test02() {
	int n = 3, m = -3;
	double expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, m, expected, "test02");
}

// wrong size
void test03() {
	int n = 0, m = 3;
	double expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, m, expected, "test03");
}

// wrong size
void test04() {
	int n = 3, m = 0;
	double expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, m, expected, "test04");
}

// matrix == null 
void test05() {
	int n = 3, m = 3;
	double expected = 0;
	int** matrix = nullptr;
	print_test(matrix, n, m, expected, "test05");
}

// matrix with all positive elements
void test06() {
	int n = 2, m = 3;
	double expected = 5.0;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {1, 2, 3};
	matrix[1] = new int[m] {7, 8, 9};

	print_test(matrix, n, m, expected, "test06");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with all negative elements
void test07() {
	int n = 2, m = 3;
	double expected = -5.0;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {-1, -2, -3};
	matrix[1] = new int[m] {-7, -8, -9};

	print_test(matrix, n, m, expected, "test07");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with positive and some zero elements
void test08() {
	int n = 2, m = 2;
	double expected = 3.5;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {0, 3};
	matrix[1] = new int[m] {4, 0};

	print_test(matrix, n, m, expected, "test08");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with negative and some zero elements
void test09() {
	int n = 2, m = 2;
	double expected = -3.5;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {0, -3};
	matrix[1] = new int[m] {-4, 0};

	print_test(matrix, n, m, expected, "test09");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with all zero elements
void test10() {
	int n = 3, m = 3;
	double expected = 0.0;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m] {0, 0, 0};
	}

	print_test(matrix, n, m, expected, "test10");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with all positive, negative and zero elements (base case)
void test11() {
	int n = 2, m = 3;
	double expected = -0.75;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {1, 0, -3};
	matrix[1] = new int[m] {0, 5, -6};

	print_test(matrix, n, m, expected, "test11");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix == horizontal vector
void test12() {
	int n = 1, m = 4;
	double expected = 2.0;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {1, 2, 3, 0};

	print_test(matrix, n, m, expected, "test12");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix == vertical vector
void test13() {
	int n = 4, m = 1;
	double expected = 2.0;

	int** matrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[m] {i};
	}

	print_test(matrix, n, m, expected, "test13");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

// matrix with only one element
void test14() {
	int n = 1, m = 1;
	double expected = 7.0;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {7};

	print_test(matrix, n, m, expected, "test14");

	delete[] matrix[0];
	delete[] matrix;
}

// basic case
void test15() {
	int n = 3, m = 4;
	double expected = 3.5;

	int** matrix = new int* [n];
	matrix[0] = new int[m] {1, 0, 2, 2};
	matrix[1] = new int[m] {1, 3, 0, 6};
	matrix[2] = new int[m] {2, 1, 8, 9};

	print_test(matrix, n, m, expected, "test15");

	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

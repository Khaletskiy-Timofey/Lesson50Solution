// Сумма элементов [The sum of elements]
// 
// Дана математическая квадратная матрица размером N.
// Необходимо разработать функцию (или программу), 
// которая вычисляет сумму элементов матрицы, 
// расположенных на главной и побочной диагоналях.
#include "logic.h"

int sum_main_and_second_diagonales_elements(int** matrix, int n)
{
	if (matrix == nullptr)
	{
		return 0;
	}

	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += matrix[i][i];
	}

	for (int i = 0; i < n; i++)
	{
		sum += matrix[i][n - i - 1];
	}

	return sum - (n % 2 == 1 ? matrix[n / 2][n / 2] : 0);
}
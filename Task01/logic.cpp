// Среднее арифметическое ненулевых элементов
// [The arithmetic mean of non-zero elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// вычисляет среднее арифметическое ненулевых элементов матрицы.

#include "logic.h"

double calculate_arithmetical_mean_of_nonzero_elements(int** matrix, int n, int m)
{
	if (matrix == nullptr || n <= 0 || m <= 0)
	{
		return 0.0;
	}

	int count = 0;
	double sum = 0.0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] != 0)
			{
				count++;
				sum += matrix[i][j];
			}
		}
	}

	return count > 0 ? sum / count : 0.0;
}
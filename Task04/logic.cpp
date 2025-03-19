// Сумма элементов столбцов с экстремальными элементами
// [The Sum of elements of columns with extreme elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// высчитывает сумму элементов в тех столбцах заданной матрицы,
// которые содержат хотя бы один экстремальный элемент.

#include "logic.h"

int find_max_element(int** matrix, int n, int m)
{
	int max_i = 0;
	int max_j = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > matrix[max_i][max_j])
			{
				max_i = i;
				max_j = j;
			}
		}
	}

	return matrix[max_i][max_j];
}

int find_min_element(int** matrix, int n, int m)
{
	int min_i = 0;
	int min_j = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] < matrix[min_i][min_j])
			{
				min_i = i;
				min_j = j;
			}
		}
	}

	return matrix[min_i][min_j];
}

int sum_elements_of_columns_with_extreme_value(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		return 0;
	}

	int max = find_max_element(matrix, n, m);
	int min = find_min_element(matrix, n, m);
	int sum = 0;

	for (int i = 0; i < m; i++)
	{
		int sum_in_column = 0;
		bool is_extreme_element = false;

		for (int j = 0; j < n; j++)
		{
			sum_in_column += matrix[j][i];
			if (matrix[j][i] == max || matrix[j][i] == min)
			{
				is_extreme_element = true;
			}
		}

		if (is_extreme_element)
		{
			sum += sum_in_column;
		}
	}

	return sum;
}
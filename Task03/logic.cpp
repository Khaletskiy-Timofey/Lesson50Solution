// Количество строк с большим количество положительных элементов
// [The Number of rows with a large number of positive elements]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию(или программу), которая находит
// количество строк, в которых положительных элементов больше 
// чем всех остальных (отрицательных и нулевых).

#include "logic.h"

int count_rows_with_more_positive_values(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		return 0;
	}

	int strings = 0;

	for (int i = 0; i < n; i++)
	{
		int positive_elements = 0;

		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] > 0)
			{
				positive_elements++;
			}
		}

		if (positive_elements > m - positive_elements)
		{
			strings++;
		}
	}

	return strings;
}
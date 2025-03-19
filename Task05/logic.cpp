// Последний локальный минимум
// [The last local minimum]
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать эффективную функцию (или программу), которая 
// находит и возвращает местоположение последнего локального минимума. 

#include "logic.h"

bool is_local_minimum(int** matrix, int n, int m, int x, int y)
{
	bool result;

	if (m == 1 && n == 1)
	{
		return false;
	}
	if (m != 1)
	{
		if (n != 1)
		{
			if (x == 0 && y == 0)
			{
				result = matrix[0][0] < matrix[0][1] && matrix[0][0] < matrix[1][0];
			}
			else if (x == m - 1 && y == 0)
			{
				result = matrix[0][m - 1] < matrix[0][m - 2] && matrix[0][m - 1] < matrix[1][m - 1];
			}
			else if (x == m - 1 && y == n - 1)
			{
				result = matrix[n - 1][m - 1] < matrix[n - 1][m - 2] && matrix[n - 1][m - 1] < matrix[n - 2][m - 1];
			}
			else if (x == 0 && y == n - 1)
			{
				result = matrix[n - 1][0] < matrix[n - 2][0] && matrix[n - 1][0] < matrix[n - 1][1];
			}
			else if (x == 0 && y != 0 && y != n - 1)
			{
				result = matrix[y][0] < matrix[y - 1][0] && matrix[y][0] < matrix[y][1] && matrix[y][0] < matrix[y + 1][0];
			}
			else if (y == 0 && x != 0 && x != m - 1)
			{
				result = matrix[0][x] < matrix[0][x - 1] && matrix[0][x] < matrix[0][x + 1] && matrix[0][x] < matrix[1][x];
			}
			else if (x == m - 1 && y != 0 && y != n - 1)
			{
				result = matrix[y][m - 1] < matrix[y - 1][m - 1] && matrix[y][m - 1] < matrix[y][m - 2] && matrix[y][m - 1] < matrix[y + 1][m - 1];
			}
			else if (y == n - 1 && x != 0 && x != m - 1)
			{
				result = matrix[n - 1][x] < matrix[n - 2][x] && matrix[n - 1][x] < matrix[n - 1][x - 1] && matrix[n - 1][x] < matrix[n - 1][x + 1];
			}
			else
			{
				result = matrix[y][x] < matrix[y - 1][x] && matrix[y][x] < matrix[y][x - 1] && matrix[y][x] < matrix[y][x + 1] && matrix[y][x] < matrix[y + 1][x];
			}
		}
		else
		{
			if (x == 0)
			{
				result = matrix[0][0] < matrix[0][1];
			}
			else if (x == m - 1)
			{
				result = matrix[0][m - 1] < matrix[0][m - 2];
			}
			else
			{
				result = matrix[0][x] < matrix[0][x - 1] && matrix[0][x] < matrix[0][x + 1];
			}
		}
	}
	else
	{
		if (y == 0)
		{
			result = matrix[0][0] < matrix[1][0];
		}
		else if (y == n - 1)
		{
			result = matrix[n - 1][0] < matrix[n - 2][0];
		}
		else
		{
			result = matrix[y][0] < matrix[y - 1][0] && matrix[y][0] < matrix[y + 1][0];
		}
	}

	return result;
}

void get_last_local_minimum(int** matrix, int n, int m, int* x, int* y)
{
	*x = 0;

	if (matrix == nullptr)
	{
		return;
	}
	
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			if (is_local_minimum(matrix, n, m, j, i))
			{
				*y = j + 1;
				*x = i + 1;
				return;
			}
		}
	}
}
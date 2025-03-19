// Минимальный максимум среди всех локальных максимумов
// [The minimum maximum among all local maxima].
// 
// Дана математическая прямоугольная матрица размером N на M.
// Необходимо разработать функцию (или программу), которая 
// находит значение локального максимума, который является
// минимальным среди всех локальных максимумов. 

#include "logic.h"

bool is_local_max(int** matrix, int n, int m, int x, int y)
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
				result = matrix[0][0] > matrix[0][1] && matrix[0][0] > matrix[1][0];
			}
			else if (x == m - 1 && y == 0)
			{
				result = matrix[0][m - 1] > matrix[0][m - 2] && matrix[0][m - 1] > matrix[1][m - 1];
			}
			else if (x == m - 1 && y == n - 1)
			{
				result = matrix[n - 1][m - 1] > matrix[n - 1][m - 2] && matrix[n - 1][m - 1] > matrix[n - 2][m - 1];
			}
			else if (x == 0 && y == n - 1)
			{
				result = matrix[n - 1][0] > matrix[n - 2][0] && matrix[n - 1][0] > matrix[n - 1][1];
			}
			else if (x == 0 && y != 0 && y != n - 1)
			{
				result = matrix[y][0] > matrix[y - 1][0] && matrix[y][0] > matrix[y][1] && matrix[y][0] > matrix[y + 1][0];
			}
			else if (y == 0 && x != 0 && x != m - 1)
			{
				result = matrix[0][x] > matrix[0][x - 1] && matrix[0][x] > matrix[0][x + 1] && matrix[0][x] > matrix[1][x];
			}
			else if (x == m - 1 && y != 0 && y != n - 1)
			{
				result = matrix[y][m - 1] > matrix[y - 1][m - 1] && matrix[y][m - 1] > matrix[y][m - 2] && matrix[y][m - 1] > matrix[y + 1][m - 1];
			}
			else if (y == n - 1 && x != 0 && x != m - 1)
			{
				result = matrix[n - 1][x] > matrix[n - 2][x] && matrix[n - 1][x] > matrix[n - 1][x - 1] && matrix[n - 1][x] > matrix[n - 1][x + 1];
			}
			else
			{
				result = matrix[y][x] > matrix[y - 1][x] && matrix[y][x] > matrix[y][x - 1] && matrix[y][x] > matrix[y][x + 1] && matrix[y][x] > matrix[y + 1][x];
			}
		}
		else
		{
			if (x == 0)
			{
				result = matrix[0][0] > matrix[0][1];
			}
			else if (x == m - 1)
			{
				result = matrix[0][m - 1] > matrix[0][m - 2];
			}
			else
			{
				result = matrix[0][x] > matrix[0][x - 1] && matrix[0][x] > matrix[0][x + 1];
			}
		}
	}
	else
	{
		if (y == 0)
		{
			result = matrix[0][0] > matrix[1][0];
		}
		else if (y == n - 1)
		{
			result = matrix[n - 1][0] > matrix[n - 2][0];
		}
		else
		{
			result = matrix[y][0] > matrix[y - 1][0] && matrix[y][0] > matrix[y + 1][0];
		}
	}

	return result;
}

int get_min_maximum(int** matrix, int n, int m)
{
	if (matrix == nullptr)
	{
		return 0;
	}

	int* local_maxs = new int[n * m];
	int local_maxs_idx = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (is_local_max(matrix, n, m, j, i))
			{
				local_maxs[local_maxs_idx] = matrix[i][j];
				local_maxs_idx++;
			}
		}
	}

	if (local_maxs_idx == 0)
	{
		return 0;
	}

	int min_idx = 0;

	for (int i = 1; i < local_maxs_idx; i++)
	{
		if (local_maxs[i] < local_maxs[min_idx])
		{
			min_idx = i;
		}
	}

	int result = local_maxs[min_idx];

	delete[] local_maxs;

	return result;
}
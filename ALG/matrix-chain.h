#pragma once
#include <algorithm>
int matrix_p[MAX_V];
int m[MAX_V][MAX_V];
int matrix_V;

int matrix_mul(int i, int j)
{
	if (m[i][j] == INF)
	{
		for (int k = i;k < j;++k)
		{
			m[i][j] = std::min(m[i][j], matrix_mul(i, k) + matrix_mul(k + 1, j) + matrix_p[i - 1] * matrix_p[k] * matrix_p[j]);
		}
	}
	return m[i][j];
}
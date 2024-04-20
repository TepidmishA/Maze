#include "funcLib.h"

int** init_matrix(int n, int m)
{
	int** matrix = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)	matrix[i] = (int*)malloc(m * sizeof(int));
	return matrix;
}

void free_matrix(int** matrix, int size)
{
	for (int i = 0; i < size; i++) free(matrix[i]);
	free(matrix);
}
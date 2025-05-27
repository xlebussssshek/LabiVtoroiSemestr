#include "class.h"

template <class M>
void Matrix<M>::clearmemory() 
{
	if (matrix != NULL) {
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
	}
	cols = 0;
	rows = 0;
}

template <class M>
void Matrix<M>::allocate_memory(int r, int c)
{
	clearmemory();
	rows = r;
	cols = c;
	if (rows <= 0 || cols <= 0)
	{
		rows = 1;
		cols = 1;
	}

	matrix = new M * [rows];
	for (int i = 0; i < rows; i++) {
		matrix[i] = new M[cols];
		for (int j = 0; j < cols; j++)
		matrix[i][j] = M();
	}
}

template class Matrix<int>;
template class Matrix<double>;





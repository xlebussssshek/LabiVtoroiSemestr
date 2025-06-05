#include "class.h"

template <class M>
void Matrix<M>::clearmemory() 
{
	if (matrix != NULL) {
		if (rows > 0 && cols > 0)
		{
			delete[] matrix[0];
		}
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

	M* temp = new M[rows * cols];
	for (int i = 0; i < rows * cols; i++)
	{
		temp[i] = M();
	}
	matrix = new M * [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = temp + i * cols;
	}
}

template class Matrix<int>;
template class Matrix<double>;





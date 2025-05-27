#include "class.h"



template <class M>
Matrix<M>::Matrix(int r, int c)
{
	rows = r;
	cols = c;
	matrix = new M * [rows];
	for (int i = 0; i < rows; i++)
		matrix[i] = new M[cols];
}

template <class M>
Matrix<M>::~Matrix()
{
	clearmemory();
}

template <class M>
void Matrix<M>::clearmemory() 
{
	if (matrix) {
		for (int i = 0; i < rows; i++)
			delete[] matrix[i];
		delete[] matrix;
		matrix = NULL;
	}
}

template class Matrix<int>;
template class Matrix<double>;





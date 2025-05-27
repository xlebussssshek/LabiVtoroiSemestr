#ifndef CLASS_H
#define CLASS_H
#include <iostream>

template<class M>
class Matrix
{
private:
	int rows, cols;
	M** matrix;

	void clearmemory();
public:
	Matrix() : rows(0), cols(0), matrix(NULL) {}
	Matrix(int r, int c);
	~Matrix();
	
	friend std::ostream& operator<<(std::ostream& out, const Matrix<M>& mat)
	{
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
				out << mat.matrix[i][j] << " ";
			out << std::endl;
		}
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Matrix<M>& mat)
	{
		if (mat.rows == 0 or mat.cols == 0)
		{
			std::cout << "\n¬ведите количество строк и столбцов матрицы: ";
			in >> mat.rows >> mat.cols;
			mat.matrix = new M*[mat.rows];
			for (int i = 0; i < mat.rows; i++)
			{
				mat.matrix[i] = new M[mat.cols];
			}
		}
		std::cout << "\n¬ведите элементы матрицы:";
		for (int i = 0; i < mat.rows; i++)
		{
			for (int j = 0; j < mat.cols; j++)
			{
				in >> mat.matrix[i][j];
			}
		}
		return in;
	}


};
#endif
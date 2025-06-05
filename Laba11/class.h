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
	void allocate_memory(int r, int c);
public:
	Matrix() : rows(1), cols(1) { allocate_memory(1, 1); }
	Matrix(int r, int c) : rows(r), cols(c) { allocate_memory(rows, cols); }
	~Matrix() { clearmemory(); }
	
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
		if (mat.matrix != NULL && (mat.rows <= 1 && mat.cols <= 1))
		{
			mat.clearmemory();
			std::cout << "\n¬ведите размеры матрицы" << std::endl;
			std::cin >> mat.rows >> mat.cols;
			mat.allocate_memory(mat.rows, mat.cols);
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
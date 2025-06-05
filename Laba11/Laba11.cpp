#include <iostream>
#include <Windows.h>

#include "class.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Matrix<int> mat_int2;
	Matrix<double> mat_doub1;

	std::cout << "\nВведите количество строк и столбцов" << std::endl;
	int rw, cl;
	std::cin >> rw >> cl;
	Matrix<int> mat_int1(rw, cl);
	std::cin >> mat_int1;
	std::cout << "Введите элементы матрицы целых чисел: " << std::endl;
	std::cin >> mat_int2;
	std::cout << "Введите элементы матрицы дробных чисел: " << std::endl;
	std::cin >> mat_doub1;
	std::cout << "Матрица целых чисел 1" << std::endl;
	std::cout << mat_int1;
	std::cout << "Матрица целых чисел 2: " << std::endl;
	std::cout << mat_int2;
	std::cout << "Матрица дробных чисел: " << std::endl;
	std::cout << mat_doub1;

}
#include <iostream>
#include "Windows.h"
#include "mass.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;

	cout << "Введите размер массива" << endl;
	cin >> n;
	MyMass mass1;
	MyMass mass2(n);
	MyMass mass3;
	MyMass mass4;

	cout << "Введите массив 1" << endl;
	cin >> mass1;
	cout << "Введите массив 2" << endl;
	cin >> mass2;
	mass3 = mass1;
	cout << "Копирование массива" << endl;
	cout << mass1;
	cout << mass3;
	cout << "Сложение массивов" << endl;
	mass4 = mass1 + mass2;
	cout << mass4;
	cout << "Слияние массивов" << endl;
	mass1 += mass2;
	cout << mass1;

	
	return 0;

}
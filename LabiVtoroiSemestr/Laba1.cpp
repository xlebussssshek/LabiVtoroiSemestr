#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ifstream fin;
	ofstream fout_p, fout_n;
	fin.open("numbers.txt", ios::_Nocreate);
	if (!fin)
	{
		cout << "\n Нет исходного файла" << endl;
		return 1;
	}
	fout_p.open("positive.txt", ios::_Noreplace);
	fout_n.open("negative.txt", ios::_Noreplace);
	if (!fout_p or !fout_n)
	{
		cout << "Не удалось создать файлы" << endl;
		return 1;
	}
	int numbers;
	while (fin >> numbers)
	{
		if (numbers > 0)
		{
			fout_p << numbers << endl;
		}
		else if (numbers < 0)
		{
			fout_n << numbers << endl;
		}
	}
	fin.close();
	fout_n.close();
	fout_p.close();

	cout << "Числа разделены" << endl;

	return 0;
}
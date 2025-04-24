#include <iostream>
using namespace std;
#include "Windows.h"
#include <cstdlib>
#include "time.h"
#include "Cilinder.h"
#include <string>
#include <fstream>

int main()
{
    double tempV, tempR;
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Cilinder A;
    Cilinder B;
    Cilinder H;
	Cilinder Out{0, 0, 0, 0, 0};
    bool flag_menu = TRUE;
    int menu_numb;

    while (flag_menu == TRUE)
    {
		cout << "----------------------------------------------------------" << endl;
		cout << "1. Ввод данных" << endl;
		cout << "2. Вывод данных" << endl;
		cout << "3. Сравнение" << endl;
		cout << "4. Сложение" << endl;
		cout << "5. Вычитание" << endl;
		cout << "6. Ввод цилиндра в текстовый файл" << endl;
		cout << "7. Вывод цилиндра из текстового файла" << endl;
		cout << "0. Выход" << endl;
		cout << "----------------------------------------------------------" << endl;
		cin >> menu_numb;
		cout << "\n";

        switch (menu_numb)
        {
		case 1:
			cout << "Введите данные для первого цилиндра" << endl;
			cin >> A;
			cout << "Введите данные для второго цилиндра" << endl;
			cin >> B;
			break;
        case 2:
			cout << "Данные первого и второго цилиндра" << endl;
			shapka();
			cout << A << endl;
            cout << B << endl;
        case 3:
			cout << "Сравнение первого цилиндра со вторым" << endl;
            if (A >= B.Ob())
            {
				cout << "Первый цилиндр больше второго" << endl;
			}
			else
			{
				cout << "Второй цилиндр больше первого" << endl;
			}
			break;
		case 4:
			cout << "Сложение первого цилиндра со вторым" << endl;
			H = A + B;
			cout << "Результат сложения" << endl;
			cout << H << endl;
			break;
		case 5:
			cout << "Вычитание первого цилиндра со второго" << endl;
			H = A - B;
			cout << "Результат вычитания" << endl;
			cout << H << endl;
			break;
		case 6:
		{
			cout << "Ввод цилиндра в текстовый файл" << endl;
			ofstream file("Cilinder.txt", ios::trunc);
			if (!file)
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				file << A;
				file.close();
				cout << "Данные записаны в файл" << endl;
			}
			break;
		}
		case 7:
		{
			cout << "Вывод цилиндра из текстового файла" << endl;
			ifstream file("Cilinder.txt");
			if (!file)
			{
				cout << "Ошибка открытия файла" << endl;
			}
			else
			{
				file >> Out;
				file.close();
				cout << "Данные прочитаны из файла" << endl;
				shapka();
				cout << Out << endl;
			}
			break;
		}
		case 0:
			flag_menu = FALSE;
			break;
		default:
			cout << "Ошибка ввода" << endl;
			break;
        }
    }
}
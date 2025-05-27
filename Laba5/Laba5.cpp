#include <iostream>
using namespace std;
#include "Windows.h"
#include <cstdlib>
#include "time.h"
#include "Cilinder.h"
#include <string>
#include <fstream>

int Cilinder::HowMany = 0;
int main()
{
    double tempV, tempR;
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Cilinder A;
    Cilinder B;
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
		cout << "8. Количество цилиндров" << endl;
		cout << "9. Создать и удалить массив из 5-ти цилиндров" << endl;
		cout << "10. Создать цилиндр с заданными параметрами и удалить его" << endl;
		cout << "11. Создать копию цилиндра А и удалить её" << endl;
		cout << "0. Выход" << endl;
		cout << "----------------------------------------------------------" << endl;
		cin >> menu_numb;
		cout << "\n";
		system("cls");

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
			break;
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
		{
			cout << "Сложение первого цилиндра со вторым" << endl;
			Cilinder H = A + B;
			cout << "Результат сложения" << endl;
			cout << H << endl;
			break;
		}
		case 5:
		{
			cout << "Вычитание первого цилиндра со второго" << endl;
			Cilinder H = A - B;
			cout << "Результат вычитания" << endl;
			cout << H << endl;
			break;
		}
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
			Cilinder Out;
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
		case 8:
			cout << "Количество цилиндров" << endl;
			cout << Cilinder::HowManyCilinders() << endl;
			break;
		case 9:
		{
			const int N = 5;
			Cilinder* mass[N];
			for (int i = 0; i < N; i++)
			{
				mass[i] = new Cilinder();
				cout << "Количество объектов: " << Cilinder::HowManyCilinders() << endl;
			}
			for (int i = 0; i < N; i++)
			{
				delete(mass[i]);
				cout << "Количество объектов: " << Cilinder::HowManyCilinders() << endl;
			}
		}
		case 10:
		{
			Cilinder* C = new Cilinder(12, 3, 9, 24.5, 99.4);
			cout << "Создан цилиндр с заданными параметрами" << endl;
			cout << "Количество объектов: " << Cilinder::HowManyCilinders() << endl;
			delete C;
			cout << "Цилиндр удалён" << endl;
			break;
		}
		case 11:
		{
			Cilinder * C = new Cilinder(A);
			cout << "Создана копия цилиндра А" << endl;
			cout << "Количество объектов: " << Cilinder::HowManyCilinders() << endl;
			delete C;
			cout << "Копия цилиндра удалена" << endl;
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
	return 0;
}
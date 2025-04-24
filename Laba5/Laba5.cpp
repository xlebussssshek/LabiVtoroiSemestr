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
    Cilinder C = A + B;
    Cilinder D = A - B;
    int const N = 3;
    Cilinder G[3];
    Cilinder H;
    cin >> H;

    ifstream inFile("Cilinder.txt", ios::trunc);
    if (!inFile)
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    ofstream outFile("Cilinder.txt");
    if (!outFile)
    {
		cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    



    cout << "Цилиндр H" << endl;
    shapka();
    cout << H << endl;

    cout << "Цилиндр А" << endl;
    shapka();
    cout << A << endl;
    cout << "Цилиндр B" << endl;
    shapka();
    cout << B << endl;
    /*cout << "Массив цилиндров:" << endl;
    shapka();
    for (int i = 0; i < N; i++)
    {
      G[i].Out();
    }*/

    Cilinder AH = A;
    cout << AH << endl;

    cout << "Введите значение для вычетания радиуса" << endl;
    cin >> tempR;
    B = B - tempR;
    cout << B << endl;

    cout << "Введите объём для сравнения" << endl;
    cin >> tempV;

    if (A >= tempV)
    {
        cout << "A больше" << endl;
    }

    cout << "Объём цилиндра A: " << A.Ob() << endl;
    cout << B.Ob() << endl;


    return 0;
}
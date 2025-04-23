#include <iostream>
using namespace std;
#include "Windows.h"
#include <cstdlib>
#include "time.h"
#include "Cilinder.h"

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


    cout << "Цилиндр А" << endl;
    shapka();
    A.Out();
    cout << "Цилиндр B" << endl;
    shapka();
    B.Out();
    /*cout << "Массив цилиндров:" << endl;
    shapka();
    for (int i = 0; i < N; i++)
    {
      G[i].Out();
    }*/

    Cilinder AH = A;
    AH.Out();

    cout << "Введите значение для вычетания радиуса" << endl;
    cin >> tempR;
    B = B - tempR;
    B.Out();

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
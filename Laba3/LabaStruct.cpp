//Функция main() пишется в виде цикла с меню, предоставляющем набор возможных действий над массивом структур.
//

//Для разработанной ранее структуры написать и протестировать функции :
//-Выборка из массива  структур по указанным ключам(по вариантам).Функция должна вывести на экран найденные структуры, а в качестве результата передает сигнал, найдены ли структуры.
//В main() добавить соответствующий пункт меню.

//-Вывод массива структур в двоичный файл.
//- Заполнение массива структур из двоичного файла;
//В main() добавить соответствующие пункты меню.




#include <iostream>
#include <Windows.h>
#include <string>
#include "struct_func.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    vector<kvartira> flat;
    string f_raion;
    int size, f_komnati, f_price, n = 0;
    bool flag = TRUE;
    bool find;
    bool flag_menu = TRUE;
    string temp;
    kvartira kv1;
    int menu_numb;
    string menu_char;
    string filenamewrite, filenameread;
    cout << "Введите размер массива" << endl;
    cin >> size;
    vector<kvartira> kv(size);

    while (flag_menu == TRUE)
    {
        cout << "Добро пожаловать в меню выбора действий" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Вам доступны следующие команды:" << endl;
        cout << "1. Заполнить одну структуры с клавиатуры" << endl;
        cout << "2. Вывести на экран одну структуры(структура ранее должна быть заполнена)" << endl;
        cout << "3. Заполинть массив структур с клавиатуры" << endl;
        cout << "4. Вывести на экран массив структур(массив ранее должнен быть заполнен или инициализирован из файла)" << endl;
        cout << "5. Воспользоваться поиском в массиве по фильтрам: Район, количество комнат, цена. (массив ранее должен быть заполнен или инициализирован из файла)" << endl;
        cout << "6. Записать в двоичный файл массив структур(массив должен быть ранее заполнен)" << endl;
        cout << "7. Инициализировать массив из структур из двоичного файла" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Для выбора команды введите её номер в списке" << endl;

        cin >> menu_numb;
        system("cls");

        switch (menu_numb)
        {
        case 1:
            cout << "\n";
            kv_in(kv1);
            break;
        case 2:
            cout << "\n";
            if (kv1.address.street == "")
            {
                cout << "Структура пуста" << endl;
                break;
            }
            struct_out(kv1);
            break;
        case 3:
            cout << "\n";
            struct_in(kv.data(), size);
            break;
        case 4:
            cout << "\n";
            if (kv[0].address.number_of_house == 0)
            {
                cout << "Массив пуст" << endl;
                break;
            }
            struct_mass_out(kv.data(), size);
            break;
        case 5:
        cout << "\n";
        while (flag == TRUE)
        {
            cout << "Введите фильтр Район, количество комнат, цена" << endl;
            cin >> f_raion;
            cin >> f_komnati;
            cin >> f_price;
            find = FALSE;
            for (int i = 0; i < size; i++)
            {
                if ((kv[i].raion == f_raion) and (kv[i].komnati == f_komnati) and (kv[i].price <= f_price))
                {
                    n = i + 1;
                    struct_out_menu(kv.data(), n);
                    find = TRUE;
                }
            }
            if (find == FALSE)
            {
                cout << "Квартиры по таким фильтрам не найдено, попробуем ещё раз? (y/n)" << endl;
                cin >> temp;
                if (temp == "n")
                {
                    flag = FALSE;
                }
                else
                {
                    flag = TRUE;
                }
            }
            else
            {
                cout << "Все квартиры найдены, продолжить поиск?(y/n)" << endl;
                cin >> temp;
                if (temp == "n")
                {
                    flag = FALSE;
                }
                else
                {
                    flag = TRUE;
                }
            }
        }
        break;
    case 6:
        cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
        cin >> filenamewrite;
        writestruct(kv.data(), size, filenamewrite);
        break;
    case 7:
        cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
        cin >> filenameread;
        readstruct(flat, filenameread);

        if (flat.empty())
        {
            cout << "Файл пуст" << endl;
            break;
        }

        cout << "Данные из файла" << endl;
        for (const auto& kv : flat)
        {
            cout << "Улица: " << kv.address.street << ", Номер дома: " << kv.address.number_of_house << ", Номер квартиры: " << kv.address.number_of_kv
                << ", Район: " << kv.raion << ", Количество комнат: " << kv.komnati << ", Цена: " << kv.price << endl;
        }
    }

    cout << "\n--------------------------------------------------------------------" << endl;
    cout << "Для выхода из программы введите n" << endl;
    cin >> menu_char;
    if (menu_char == "n")
    {
        flag_menu = FALSE;
    }
    else
    {
        system("cls");
    }
  }

  return 0;
}
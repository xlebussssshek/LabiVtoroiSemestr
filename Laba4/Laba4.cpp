//Сделать удаление последнего элемента+, удаление по ключевому полю(в функции поиска сделать удаление найденной структуры+, редактирование+)
//поправить работу с файлами+
#include <iostream>
#include <Windows.h>
#include <string>
#include "list_func.h"
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string f_raion;
    int size, f_komnati, f_price, n = 0;
    bool flag = TRUE;
    bool find;
    bool flag_menu = TRUE;
    string temp_str;
    kvartira kv1;
    int menu_numb;
    string menu_char;
    string filenamewrite, filenameread;
    Node_queue* head = NULL;
    Node_queue* tail = NULL;

    while (flag_menu == TRUE)
    {
        cout << "Добро пожаловать в меню выбора действий" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Вам доступны следующие команды:" << endl;
        cout << "1. Заполнить одну структуры с клавиатуры" << endl;
        cout << "2. Вывести на экран одну структуры" << endl;
        cout << "3. Добавить структуру в список" << endl;
        cout << "4. Вывести на экран список сначала" << endl;
        cout << "5. Воспользоваться поиском в списке по фильтрам: Район, количество комнат, цена." << endl;
        cout << "6. Записать в двоичный файл список" << endl;
        cout << "7. Инициализировать список из двоичного файла" << endl;
        cout << "8. Удалить последний элемент списка" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "Для выбора команды введите её номер в списке" << endl;
        cout << "Чтобы выйти из программы введите 0" << endl;

        cin >> menu_numb;
        system("cls");

        switch (menu_numb)
        {
        case 0:
            return 1;
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
            shapka();
            struct_out(kv1);
            break;
        case 3:
            cout << "\n";
            list_append(head, tail, kv1);
            break;
        case 4:
            cout << "\n";
            if (head == NULL)
            {
                cout << "Список пуст" << endl;
                break;
            }
            shapka();
            headlist_out(head, tail);
            break;
        case 5:
            cout << "\n";
            if (head == NULL)
            {
                cout << "Список пуст" << endl;
                break;
            }
            flag = TRUE;
            while (flag == TRUE)
            {
                cout << "Введите фильтр Район, количество комнат, цена" << endl;
                cin >> f_raion;
                cin >> f_komnati;
                cin >> f_price;
                find = FALSE;
                Node_queue* poisk = head;
                int swtch;
                shapka();
                while (poisk != NULL)
                {
                    if (poisk->data.raion == f_raion and poisk->data.komnati == f_komnati and poisk->data.price <= f_price)
                    {
                        find = TRUE;
                        struct_out(poisk->data);
                        cout << "--------------------------------------------------------------------" << endl;
                        cout << "Доступны следующие действия:" << endl;
                        cout << "1. Удалить структуру" << endl;
                        cout << "2. Редактировать структуру" << endl;
                        cout << "Для продолжения поиска введите любой символ" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        cout << "Введите ключ операции" << endl;
                        cin >> swtch;
                        system("cls");
                        switch (swtch)
                        {
                        case 1:
                            if (tail == poisk)
                            {
                                lastlist_delete(head, tail);
                            }
                            else
                            {
                                Node_queue* temptail = tail;
                                temptail = head;
                                while (temptail != tail)
                                {
                                    if (temptail->next == poisk)
                                    {
                                        deletecurrent(head, tail, poisk);
                                    }
                                    else
                                    {
                                        temptail = temptail->next;
                                    }
                                }
                            }
                            break;
                        case 2:
                            kv1 = poisk->data;
                            editstruct(kv1);
                            poisk->data = kv1;
                            break;
                        default:
                            break;
                        }
                    }
                    poisk = poisk->next;
                }
                if (find == FALSE)
                {
                    system("cls");
                    cout << "Квартир по таким фильтрам не найдено, попробуем ещё раз? (y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n")
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
                    cout << "Все квартиры найдены, продолжить поиск с другими параметрами?(y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n")
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
            if (head == NULL)
            {
                cout << "Список пуст и не может быть записан в файл" << endl;
                break;
            }
            cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
            cin >> filenamewrite;
            writestruct(head, filenamewrite);
            break;
        case 7:
            cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
            cin >> filenameread;
            readstruct(head, tail, filenameread);

            if (head == NULL)
            {
                cout << "Файл пуст" << endl;
                break;
            }
            cout << "Данные из файла" << endl;
            shapka();
            headlist_out(head, tail);
            break;
        case 8:
            lastlist_delete(head, tail);
            break;
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

  while (head != NULL) list_delete(head);
  return 0;
}
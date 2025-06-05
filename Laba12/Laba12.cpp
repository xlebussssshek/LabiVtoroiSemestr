#include <iostream>
#include <Windows.h>
#include <string>
#include "class.h"
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string f_raion;
    int f_komnati, f_price, n = 0;
    bool flag = true;
    bool find;
    bool flag_menu = true;
    string temp_str;
    Apartment kv1;
    int menu_numb;
    string menu_char;
    string filenamewrite, filenameread;
    Node<Apartment>* head = NULL;
    Node<Apartment>* tail = NULL;
    Node<Apartment> node;

    while (flag_menu) {
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

        switch (menu_numb) {
        case 0:
            return 1;
        case 1:
            cout << "\n";
            node.kv_in(kv1);
            break;
        case 2:
            cout << "\n";
            if (kv1.address.street == "") {
                cout << "Структура пуста" << endl;
                break;
            }
            node.shapka();
            node.struct_out(kv1);
            break;
        case 3:
            cout << "\n";
            node.list_append(head, tail, kv1);
            break;
        case 4:
            cout << "\n";
            if (head == NULL) {
                cout << "Список пуст" << endl;
                break;
            }
            node.shapka();
            node.headlist_out(head, tail);
            break;
        case 5:
            cout << "\n";
            if (head == NULL) {
                cout << "Список пуст" << endl;
                break;
            }
            flag = true;
            while (flag) {
                cout << "Введите фильтр Район, количество комнат, цена" << endl;
                cin >> f_raion;
                cin >> f_komnati;
                cin >> f_price;
                find = false;
                Node<Apartment>* poisk = head;
                int swtch;
                node.shapka();
                while (poisk != NULL) {
                    if (poisk->data.raion == f_raion && poisk->data.komnati == f_komnati && poisk->data.price <= f_price) {
                        find = true;
                        node.struct_out(poisk->data);
                        cout << "--------------------------------------------------------------------" << endl;
                        cout << "Доступны следующие действия:" << endl;
                        cout << "1. Удалить структуру" << endl;
                        cout << "2. Редактировать структуру" << endl;
                        cout << "Для продолжения поиска введите любой символ" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        cout << "Введите ключ операции" << endl;
                        cin >> swtch;
                        system("cls");
                        switch (swtch) {
                        case 1:
                            if (tail == poisk) {
                                node.lastlist_delete(head, tail);
                            }
                            else {
                                node.deletecurrent(head, tail, poisk);
                            }
                            break;
                        case 2:
                            kv1 = poisk->data;
                            node.editstruct(kv1);
                            poisk->data = kv1;
                            break;
                        default:
                            break;
                        }
                    }
                    poisk = poisk->next;
                }
                if (!find) {
                    system("cls");
                    cout << "Квартир по таким фильтрам не найдено, попробуем ещё раз? (y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n") {
                        flag = false;
                    }
                }
                else {
                    cout << "Все квартиры найдены, продолжить поиск с другими параметрами?(y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n") {
                        flag = false;
                    }
                }
            }
            break;
        case 6:
            if (head == NULL) {
                cout << "Список пуст и не может быть записан в файл" << endl;
                break;
            }
            cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
            cin >> filenamewrite;
            node.writestruct(head, filenamewrite);
            break;
        case 7:
            cout << "\nВведите название файла и его расширение(Пример: struct.bin)" << endl;
            cin >> filenameread;
            node.readstruct(head, tail, filenameread);

            if (head == NULL) {
                cout << "Файл пуст" << endl;
                break;
            }
            cout << "Данные из файла" << endl;
            node.shapka();
            node.headlist_out(head, tail);
            break;
        case 8:
            node.lastlist_delete(head, tail);
            break;
        }

        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "Для выхода из программы введите n" << endl;
        cin >> menu_char;
        if (menu_char == "n") {
            flag_menu = false;
        }
        else {
            system("cls");
        }
    }

    while (head != NULL) node.list_delete(head);
    return 0;
}








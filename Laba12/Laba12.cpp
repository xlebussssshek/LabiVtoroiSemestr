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
        cout << "����� ���������� � ���� ������ ��������" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "��� �������� ��������� �������:" << endl;
        cout << "1. ��������� ���� ��������� � ����������" << endl;
        cout << "2. ������� �� ����� ���� ���������" << endl;
        cout << "3. �������� ��������� � ������" << endl;
        cout << "4. ������� �� ����� ������ �������" << endl;
        cout << "5. ��������������� ������� � ������ �� ��������: �����, ���������� ������, ����." << endl;
        cout << "6. �������� � �������� ���� ������" << endl;
        cout << "7. ���������������� ������ �� ��������� �����" << endl;
        cout << "8. ������� ��������� ������� ������" << endl;
        cout << "--------------------------------------------------------------------" << endl;
        cout << "��� ������ ������� ������� � ����� � ������" << endl;
        cout << "����� ����� �� ��������� ������� 0" << endl;

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
                cout << "��������� �����" << endl;
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
                cout << "������ ����" << endl;
                break;
            }
            node.shapka();
            node.headlist_out(head, tail);
            break;
        case 5:
            cout << "\n";
            if (head == NULL) {
                cout << "������ ����" << endl;
                break;
            }
            flag = true;
            while (flag) {
                cout << "������� ������ �����, ���������� ������, ����" << endl;
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
                        cout << "�������� ��������� ��������:" << endl;
                        cout << "1. ������� ���������" << endl;
                        cout << "2. ������������� ���������" << endl;
                        cout << "��� ����������� ������ ������� ����� ������" << endl;
                        cout << "--------------------------------------------------------------------" << endl;
                        cout << "������� ���� ��������" << endl;
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
                    cout << "������� �� ����� �������� �� �������, ��������� ��� ���? (y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n") {
                        flag = false;
                    }
                }
                else {
                    cout << "��� �������� �������, ���������� ����� � ������� �����������?(y/n)" << endl;
                    cin >> temp_str;
                    if (temp_str == "n") {
                        flag = false;
                    }
                }
            }
            break;
        case 6:
            if (head == NULL) {
                cout << "������ ���� � �� ����� ���� ������� � ����" << endl;
                break;
            }
            cout << "\n������� �������� ����� � ��� ����������(������: struct.bin)" << endl;
            cin >> filenamewrite;
            node.writestruct(head, filenamewrite);
            break;
        case 7:
            cout << "\n������� �������� ����� � ��� ����������(������: struct.bin)" << endl;
            cin >> filenameread;
            node.readstruct(head, tail, filenameread);

            if (head == NULL) {
                cout << "���� ����" << endl;
                break;
            }
            cout << "������ �� �����" << endl;
            node.shapka();
            node.headlist_out(head, tail);
            break;
        case 8:
            node.lastlist_delete(head, tail);
            break;
        }

        cout << "\n--------------------------------------------------------------------" << endl;
        cout << "��� ������ �� ��������� ������� n" << endl;
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








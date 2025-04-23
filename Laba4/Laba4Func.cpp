#include <iostream>
#include "list_func.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void shapka()
{
    cout << left << setw(10) << "Улица" << setw(5) << "Дом" << setw(5) << "Кв." << setw(10) << "Район"
        << setw(8) << "Комнат" << setw(10) << "Цена" << endl;
}


void struct_out(const kvartira kv1)
{
    cout << kv1.address.street << ", " << kv1.address.number_of_house << ", " << kv1.address.number_of_kv;
    cout << ",     " << kv1.raion << ", " << kv1.komnati << ", " << kv1.price << endl;

}

void adr_in(Address_s& adr)
{
    cout << "Введите улицу, номер дома, номер квартиры" << endl;
    cin >> adr.street;
    cin >> adr.number_of_house;
    cin >> adr.number_of_kv;
}

void kv_in(kvartira& kv)
{
    adr_in(kv.address);
    cout << "\nВведите район, количество комнат, цену" << endl;
    cin >> kv.raion;
    cin >> kv.komnati;
    cin >> kv.price;
    return;
}

void struct_in(kvartira kv[], const int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ". ";
        kv_in(kv[i]);
    }
}

void struct_mass_out(const kvartira kv[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\tКвартира под номером " << i + 1 << endl;
        struct_out(kv[i]);
        cout << "---------------------------------------------------------------" << endl;
    }
}

void struct_out_menu(const kvartira kv[], int n)
{

    {
        cout << "\t\tНайденная квартира под номером " << n << endl;
        struct_out(kv[n - 1]);
    }
}


void writestruct(Node_queue* head, const string& filenamewrite)
{
    ofstream file(filenamewrite, ios::binary);

    if (!file)
    {
        cout << "Не удалось открыть файл для записи" << endl;
        return;
    }

    Node_queue* temp_list = head;

    while (temp_list != NULL)
    {

        size_t streetLen = temp_list->data.address.street.size();
        file.write(reinterpret_cast<const char*>(&streetLen), sizeof(streetLen));
        file.write(temp_list->data.address.street.c_str(), streetLen);

        file.write(reinterpret_cast<const char*>(&temp_list->data.address.number_of_house), sizeof(temp_list->data.address.number_of_house));
        file.write(reinterpret_cast<const char*>(&temp_list->data.address.number_of_kv), sizeof(temp_list->data.address.number_of_kv));

        size_t raionLen = temp_list->data.raion.size();
        file.write(reinterpret_cast<const char*>(&raionLen), sizeof(raionLen));
        file.write(temp_list->data.raion.c_str(), raionLen);

        file.write(reinterpret_cast<const char*>(&temp_list->data.komnati), sizeof(temp_list->data.komnati));
        file.write(reinterpret_cast<const char*>(&temp_list->data.price), sizeof(temp_list->data.price));

        temp_list = temp_list->next;
    }

    cout << "Файл успешно записан" << endl;

    file.close();
}


bool readstruct(Node_queue*& head, Node_queue*& tail, const string& filenameread)
{
    ifstream file(filenameread, ios::binary);

    if (!file)
    {
        cout << "Не удалось открыть файл" << endl;
        return false;
    }

    kvartira temp_kv;

    while (!(file.eof()))
    {

        size_t streetLen;
        if (!(file.read(reinterpret_cast<char*>(&streetLen), sizeof(streetLen)))) return false;
        temp_kv.address.street.resize(streetLen);
        if (!(file.read(&temp_kv.address.street[0], streetLen))) return false;

        if (!(file.read(reinterpret_cast<char*>(&temp_kv.address.number_of_house), sizeof(temp_kv.address.number_of_house)))) return false;
        if (!(file.read(reinterpret_cast<char*>(&temp_kv.address.number_of_kv), sizeof(temp_kv.address.number_of_kv)))) return false;

        size_t raionLen;
        if (!(file.read(reinterpret_cast<char*>(&raionLen), sizeof(raionLen)))) return false;
        temp_kv.raion.resize(raionLen);
        if (!(file.read(&temp_kv.raion[0], raionLen))) return false;

        if (!(file.read(reinterpret_cast<char*>(&temp_kv.komnati), sizeof(temp_kv.komnati)))) return false;
        if (!(file.read(reinterpret_cast<char*>(&temp_kv.price), sizeof(temp_kv.price)))) return false;

        list_append(head, tail, temp_kv);
    }
    file.close();
    return true;
}
void list_append(Node_queue*& head, Node_queue*& tail, const kvartira& fl)
{
    Node_queue* newNode = new Node_queue;
    newNode->data = fl;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void headlist_out(Node_queue*& head, Node_queue*& tail)
{
    Node_queue* temp = head;
    while (temp != tail)
    {
        if (temp != NULL)
        {
            struct_out(temp->data);
            temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }
    struct_out(temp->data);
    cout << endl;
}

void list_delete(Node_queue*& head)
{
    if (head != NULL)
    {
        Node_queue* temp = head;
        head = head->next;
        delete temp;
    }
}

void lastlist_delete(Node_queue*& head, Node_queue*& tail)
{
    if (head == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            cout << "Последний элемент списка был удалён" << endl;
        }
        else
        {
            Node_queue* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            tail = temp;
            tail->next = NULL;
            cout << "Элемент удалён" << endl;
            return;
        }
    }
}

void deletecurrent(Node_queue*& head, Node_queue*& tail, Node_queue*& poisk)
{
    if (head == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        if (head == tail)
        {
            head = NULL;
            tail = NULL;
            cout << "Последний элемент списка был удалён" << endl;
        }
        else
        {
            Node_queue* temp = head;
            while (temp->next != poisk)
            {
                temp = temp->next;
            }
            temp->next = poisk->next;
            poisk = NULL;
            poisk = temp;
            cout << "Элемент удалён" << endl;
        }
    }
}

void editstruct(kvartira& kv1)
{
    bool flag_swth = 1;
    int tempswtch;
    string tmpstr;
    int tmpint;
    while (flag_swth == 1)
    {
        cout << "Структура в настоящий момент" << endl;
        shapka();
        struct_out(kv1);
        cout << "Выберите пункт, который хотите поменять:" << endl;
        cout << "1. Улица" << endl;
        cout << "2. Номер дома" << endl;
        cout << "3. Номер квартиры" << endl;
        cout << "4. Район" << endl;
        cout << "5. Количество комнат" << endl;
        cout << "6. Цена" << endl;
        cout << "Для выхода из меню редактора введите любой иной символ" << endl;
        cin >> tempswtch;
        switch (tempswtch)
        {
        case 1:
            cout << "Введите улицу" << endl;
            cin >> tmpstr;
            kv1.address.street = tmpstr;
            system("cls");
            break;
        case 2:
            cout << "Введите номер дома" << endl;
            cin >> tmpint;
            kv1.address.number_of_house = tmpint;
            system("cls");
            break;
        case 3:
            cout << "Введите номер квартиры" << endl;
            cin >> tmpint;
            kv1.address.number_of_kv = tmpint;
            system("cls");
            break;
        case 4:
            cout << "Введите район" << endl;
            cin >> tmpstr;
            kv1.raion = tmpstr;
            system("cls");
            break;
        case 5:
            cout << "Введите количество комнат" << endl;
            cin >> tmpint;
            kv1.komnati = tmpint;
            system("cls");
            break;
        case 6:
            cout << "Введите цену" << endl;
            cin >> tmpint;
            kv1.price = tmpint;
            system("cls");
            break;
        default:
            flag_swth = 0;
            system("cls");
        }
    }
}
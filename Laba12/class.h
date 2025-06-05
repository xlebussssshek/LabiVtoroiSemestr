#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

class Address {
public:
    string street;
    int number_of_house;
    int number_of_kv;
};

class Apartment {
public:
    Address address;
    string raion;
    int komnati;
    int price;

    Apartment& operator=(const Apartment& a) {
        address.street = a.address.street;
        address.number_of_house = a.address.number_of_house;
        address.number_of_kv = a.address.number_of_kv;
        raion = a.raion;
        komnati = a.komnati;
        price = a.price;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Apartment& apt) {
        os  << apt.address << "\n"
            << apt.raion << "\n"
            << apt.komnati << "\n"
            << apt.price;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Apartment& apt) {
        is >> apt.address;
        std::getline(is >> std::ws, apt.raion);
        is >> apt.komnati;
        is >> apt.price;
        return is;
    }
};

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() : next(NULL) {}
    void shapka();
    void adr_in(Address& adr);
    void kv_in(Apartment& kv);
    void struct_out(const Apartment& kv1);
    void list_append(Node<T>*& head, Node<T>*& tail, const Apartment& fl);
    void headlist_out(Node<T>*& head, Node<T>*& tail);
    void list_delete(Node<T>*& head);
    void lastlist_delete(Node<T>*& head, Node<T>*& tail);
    void deletecurrent(Node<T>*& head, Node<T>*& tail, Node<T>*& poisk);
    void editstruct(Apartment& kv1);
    void writestruct(Node<T>* head, const string& filenamewrite);
    bool readstruct(Node<T>*& head, Node<T>*& tail, const string& filenameread);
};


using namespace std;

template <typename T>
void Node<T>::shapka() {
    cout << left << setw(10) << "Улица" << setw(5) << "Дом" << setw(5) << "Кв." << setw(10) << "Район"
        << setw(8) << "Комнат" << setw(10) << "Цена" << endl;
}

template <typename T>
void Node<T>::struct_out(const Apartment& kv1) {
    cout << kv1.address.street << ", " << kv1.address.number_of_house << ", " << kv1.address.number_of_kv;
    cout << ",     " << kv1.raion << ", " << kv1.komnati << ", " << kv1.price << endl;
}

template <typename T>
void Node<T>::adr_in(Address& adr) {
    cout << "Введите улицу, номер дома, номер квартиры" << endl;
    cin >> adr.street;
    cin >> adr.number_of_house;
    cin >> adr.number_of_kv;
}

template <typename T>
void Node<T>::kv_in(Apartment& kv) {
    adr_in(kv.address);
    cout << "\nВведите район, количество комнат, цену" << endl;
    cin >> kv.raion;
    cin >> kv.komnati;
    cin >> kv.price;
}

template <typename T>
void Node<T>::list_append(Node<T>*& head, Node<T>*& tail, const Apartment& fl) {
    Node<T>* newNode = new Node<T>;
    newNode->data = fl;
    newNode->next = NULL;

    if (head == NULL) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void Node<T>::headlist_out(Node<T>*& head, Node<T>*& tail) {
    Node<T>* temp = head;
    while (temp != tail) {
        if (temp != NULL) {
            struct_out(temp->data);
            temp = temp->next;
        }
        else {
            temp = temp->next;
        }
    }
    struct_out(temp->data);
    cout << endl;
}

template <typename T>
void Node<T>::list_delete(Node<T>*& head) {
    if (head != NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Node<T>::lastlist_delete(Node<T>*& head, Node<T>*& tail) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            cout << "Последний элемент списка был удалён" << endl;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = NULL;
            cout << "Элемент удалён" << endl;
        }
    }
}

template <typename T>
void Node<T>::deletecurrent(Node<T>*& head, Node<T>*& tail, Node<T>*& poisk) {
    if (head == NULL) {
        cout << "Список пуст" << endl;
    }
    else {
        if (head == tail) {
            delete head;
            head = NULL;
            tail = NULL;
            cout << "Последний элемент списка был удалён" << endl;
        }
        else {
            if (poisk == head) {
                Node<T>* temp = head;
                head = head->next;
                delete temp;
            }
            else {
                Node<T>* temp = head;
                while (temp->next != poisk) {
                    temp = temp->next;
                }
                temp->next = poisk->next;
                if (poisk == tail) {
                    tail = temp;
                }
                delete poisk;
                cout << "Элемент удалён" << endl;
            }
        }
    }
}

template <typename T>
void Node<T>::editstruct(Apartment& kv1) {
    bool flag_swth = true;
    int tempswtch;
    Apartment tmpstr;
    int tmpint;
    while (flag_swth) {
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
        switch (tempswtch) {
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
            flag_swth = false;
            system("cls");
        }
    }
}

template <typename T>
void Node<T>::writestruct(Node<T>* head, const string& filenamewrite) {
    ofstream file(filenamewrite, ios::binary);

    if (!file) {
        cout << "Не удалось открыть файл для записи" << endl;
        return;
    }

    Node<T>* temp_list = head;

    while (temp_list != NULL) {
        size_t streetLen = temp_list->data.address.street.size();
        file.write(reinterpret_cast<const char*>(&streetLen), sizeof(streetLen));
        file.write(temp_list->data.address.street.c_str(), streetLen);

        file.write(reinterpret_cast<const char*>(&temp_list->data.address.number_of_house),
            sizeof(temp_list->data.address.number_of_house));
        file.write(reinterpret_cast<const char*>(&temp_list->data.address.number_of_kv),
            sizeof(temp_list->data.address.number_of_kv));

        size_t raionLen = temp_list->data.raion.size();
        file.write(reinterpret_cast<const char*>(&raionLen), sizeof(raionLen));
        file.write(temp_list->data.raion.c_str(), raionLen);

        file.write(reinterpret_cast<const char*>(&temp_list->data.komnati),
            sizeof(temp_list->data.komnati));
        file.write(reinterpret_cast<const char*>(&temp_list->data.price),
            sizeof(temp_list->data.price));

        temp_list = temp_list->next;
    }

    cout << "Файл успешно записан" << endl;
    file.close();
}

template <typename T>
bool Node<T>::readstruct(Node<T>*& head, Node<T>*& tail, const string& filenameread) {
    ifstream file(filenameread, ios::binary);

    if (!file) {
        cout << "Не удалось открыть файл" << endl;
        return false;
    }

    Apartment temp_kv;

    while (!file.eof()) {
        size_t streetLen;
        if (!file.read(reinterpret_cast<char*>(&streetLen), sizeof(streetLen))) break;
        temp_kv.address.street.resize(streetLen);
        if (!file.read(&temp_kv.address.street[0], streetLen)) break;

        if (!file.read(reinterpret_cast<char*>(&temp_kv.address.number_of_house),
            sizeof(temp_kv.address.number_of_house))) break;
        if (!file.read(reinterpret_cast<char*>(&temp_kv.address.number_of_kv),
            sizeof(temp_kv.address.number_of_kv))) break;

        size_t raionLen;
        if (!file.read(reinterpret_cast<char*>(&raionLen), sizeof(raionLen))) break;
        temp_kv.raion.resize(raionLen);
        if (!file.read(&temp_kv.raion[0], raionLen)) break;
        if (!file.read(reinterpret_cast<char*>(&temp_kv.komnati), sizeof(temp_kv.komnati))) break;
        if (!file.read(reinterpret_cast<char*>(&temp_kv.price), sizeof(temp_kv.price))) break;
        list_append(head, tail, temp_kv);
    }

    file.close();
    return true;
}
#endif
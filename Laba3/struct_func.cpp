#include <iostream>
#include "struct_func.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


void struct_out(const kvartira kv1)
{
    cout << left << setw(10) << "Улица" << setw(5) << "Дом" << setw(5) << "Кв." << setw(10) << "Район"
        << setw(8) << "Комнат" << setw(10) << "Цена" << endl;
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


void writestruct(const kvartira kv[], int size, const string& filenamewrite)
{
    ofstream file(filenamewrite, ios::binary);

    if (!file)
    {
        cout << "Не удалось открыть файл для записи" << endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&size), sizeof(size));

    for (int i = 0; i < size; i++)
    {

        size_t streetLen = kv[i].address.street.size();
        file.write(reinterpret_cast<const char*>(&streetLen), sizeof(streetLen));
        file.write(kv[i].address.street.c_str(), streetLen);

        file.write(reinterpret_cast<const char*>(&kv[i].address.number_of_house), sizeof(kv[i].address.number_of_house));
        file.write(reinterpret_cast<const char*>(&kv[i].address.number_of_kv), sizeof(kv[i].address.number_of_kv));

        size_t raionLen = kv[i].raion.size();
        file.write(reinterpret_cast<const char*>(&raionLen), sizeof(raionLen));
        file.write(kv[i].raion.c_str(), raionLen);

        file.write(reinterpret_cast<const char*>(&kv[i].komnati), sizeof(kv[i].komnati));
        file.write(reinterpret_cast<const char*>(&kv[i].price), sizeof(kv[i].price));
    }

    cout << "Файл успешно записан" << endl;

    file.close();
}


bool readstruct(vector<kvartira>& flat, const string& filenameread)
{
    ifstream file(filenameread, ios::binary);

    if (!file)
    {
        cout << "Не удалось открыть файл" << endl;
        return false;
    }

    int sizef;
    if (!(file.read(reinterpret_cast<char*>(&sizef), sizeof(sizef))))
    {
        cout << "Ошибка чтения размера массива" << endl;
        return false;
    };

    if (sizef == 0 || sizef > 1000000)
    {
        cout << "Неверный размер массива: " << sizef << endl;
        return false;
    }

    flat.resize(sizef);


    for (size_t i = 0; i < sizef; i++)
    {

        size_t streetLen;
        if (!(file.read(reinterpret_cast<char*>(&streetLen), sizeof(streetLen)))) return false;
        flat[i].address.street.resize(streetLen);
        if (!(file.read(&flat[i].address.street[0], streetLen))) return false;

        if (!(file.read(reinterpret_cast<char*>(&flat[i].address.number_of_house), sizeof(flat[i].address.number_of_house)))) return false;
        if (!(file.read(reinterpret_cast<char*>(&flat[i].address.number_of_kv), sizeof(flat[i].address.number_of_kv)))) return false;

        size_t raionLen;
        if (!(file.read(reinterpret_cast<char*>(&raionLen), sizeof(raionLen)))) return false;
        flat[i].raion.resize(raionLen);
        if (!(file.read(&flat[i].raion[0], raionLen))) return false;

        if (!(file.read(reinterpret_cast<char*>(&flat[i].komnati), sizeof(flat[i].komnati)))) return false;
        if (!(file.read(reinterpret_cast<char*>(&flat[i].price), sizeof(flat[i].price)))) return false;

    }
    file.close();
    return true;
}
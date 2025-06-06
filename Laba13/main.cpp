#include <iostream>
#include <Windows.h>
#include "class.h"

const int MAX_PRODUCTS = 100;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Product* products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить игрушку\n";
        std::cout << "2. Добавить молочный продукт\n";
        std::cout << "3. Показать все продукты\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        system("cls");

        switch (choice) {
        case 1: {
            if (productCount >= MAX_PRODUCTS) {
                std::cout << "Достигнуто максимальное количество продуктов!\n";
                break;
            }
            std::string name, barcode;
            double price;
            int age;
            std::cout << "Введите название игрушки: ";
            std::cin >> name;
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите штрих-код: ";
            std::cin >> barcode;
            std::cout << "Введите возрастное ограничение: ";
            std::cin >> age;
            products[productCount++] = new Toy(name, price, barcode, age);
            break;
        }
        case 2: {
            if (productCount >= MAX_PRODUCTS) {
                std::cout << "Достигнуто максимальное количество продуктов!\n";
                break;
            }
            std::string name, expiryDate;
            double price;
            std::cout << "Введите название молочного продукта: ";
            std::cin >> name;
            std::cout << "Введите цену: ";
            std::cin >> price;
            std::cout << "Введите срок годности: ";
            std::cin >> expiryDate;
            products[productCount++] = new MolochProduct(name, price, expiryDate);
            break;
        }
        case 3:
            std::cout << "\nСписок всех продуктов (" << productCount << "):\n";
            for (int i = 0; i < productCount; ++i) {
                products[i]->Show();
            }
            break;
        case 0:
            std::cout << "Выход...\n";
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    } while (choice != 0);


    for (int i = 0; i < productCount; ++i) {
        delete products[i];
    }

    return 0;
}
#include "class.h"


Product::Product(const std::string& n, double p) : name(n), price(p) {}


Product::~Product() {}


void Product::Use() {
    std::cout << "Используется продукт: " << name << std::endl;
}


double Product::CalculateCost(int quantity) const {
    return price * quantity;
}


std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }


Toy::Toy(const std::string& n, double p, const std::string& bc, int age)
    : Product(n, p), barcode(bc), ageLimit(age) {}

void Toy::Show() const {
    std::cout << "Игрушка: " << name << ", цена: " << price
        << ", штрих-код: " << barcode
        << ", возраст: " << ageLimit << "+" << std::endl;
}


MolochProduct::MolochProduct(const std::string& n, double p, const std::string& exp)
    : Product(n, p), expiryDate(exp) {}


void MolochProduct::Show() const {
    std::cout << "Молочный продукт: " << name << ", цена: " << price
        << ", срок годности: " << expiryDate << std::endl;
}
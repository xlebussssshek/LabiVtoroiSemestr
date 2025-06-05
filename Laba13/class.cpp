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


Goods::Goods(const std::string& n, double p, const std::string& bc)
    : Product(n, p), barcode(bc) {}


void Goods::Show() const {
    std::cout << "Товар: " << name << ", цена: " << price
        << ", штрих-код: " << barcode << std::endl;
}


void Goods::Use() {
    std::cout << "Товар " << name << " используется по назначению" << std::endl;
}


Toy::Toy(const std::string& n, double p, const std::string& bc, int age)
    : Product(n, p), Goods(n, p, bc), ageLimit(age) {}


void Toy::Show() const {
    std::cout << "Игрушка: " << name << ", цена: " << price
        << ", возрастное ограничение: " << ageLimit << "+" << std::endl;
}

void Toy::Play() {
    std::cout << "Играем с игрушкой " << name << std::endl;
}


MolochProduct::MolochProduct(const std::string& n, double p, const std::string& exp)
    : Product(n, p), expiryDate(exp) {}


void MolochProduct::Show() const {
    std::cout << "Молочный продукт: " << name << ", цена: " << price
        << ", срок годности: " << expiryDate << std::endl;
}


void MolochProduct::CheckFreshness() const {
    std::cout << "Проверяем свежесть продукта " << name << std::endl;
}
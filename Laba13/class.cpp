#include "class.h"


Product::Product(const std::string& n, double p) : name(n), price(p) {}


Product::~Product() {}


void Product::Use() {
    std::cout << "������������ �������: " << name << std::endl;
}


double Product::CalculateCost(int quantity) const {
    return price * quantity;
}


std::string Product::getName() const { return name; }
double Product::getPrice() const { return price; }


Toy::Toy(const std::string& n, double p, const std::string& bc, int age)
    : Product(n, p), barcode(bc), ageLimit(age) {}

void Toy::Show() const {
    std::cout << "�������: " << name << ", ����: " << price
        << ", �����-���: " << barcode
        << ", �������: " << ageLimit << "+" << std::endl;
}


MolochProduct::MolochProduct(const std::string& n, double p, const std::string& exp)
    : Product(n, p), expiryDate(exp) {}


void MolochProduct::Show() const {
    std::cout << "�������� �������: " << name << ", ����: " << price
        << ", ���� ��������: " << expiryDate << std::endl;
}
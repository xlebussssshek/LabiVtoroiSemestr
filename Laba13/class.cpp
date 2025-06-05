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


Goods::Goods(const std::string& n, double p, const std::string& bc)
    : Product(n, p), barcode(bc) {}


void Goods::Show() const {
    std::cout << "�����: " << name << ", ����: " << price
        << ", �����-���: " << barcode << std::endl;
}


void Goods::Use() {
    std::cout << "����� " << name << " ������������ �� ����������" << std::endl;
}


Toy::Toy(const std::string& n, double p, const std::string& bc, int age)
    : Product(n, p), Goods(n, p, bc), ageLimit(age) {}


void Toy::Show() const {
    std::cout << "�������: " << name << ", ����: " << price
        << ", ���������� �����������: " << ageLimit << "+" << std::endl;
}

void Toy::Play() {
    std::cout << "������ � �������� " << name << std::endl;
}


MolochProduct::MolochProduct(const std::string& n, double p, const std::string& exp)
    : Product(n, p), expiryDate(exp) {}


void MolochProduct::Show() const {
    std::cout << "�������� �������: " << name << ", ����: " << price
        << ", ���� ��������: " << expiryDate << std::endl;
}


void MolochProduct::CheckFreshness() const {
    std::cout << "��������� �������� �������� " << name << std::endl;
}
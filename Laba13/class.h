#ifndef CLASS_H
#define CLASS_H

#include <string>
#include <iostream>

class Product {
protected:
    std::string name;
    double price;
public:
    Product(const std::string& n, double p);
    virtual ~Product();

    virtual void Show() const = 0;
    virtual void Use();
    virtual double CalculateCost(int quantity) const;

    std::string getName() const;
    double getPrice() const;
};


class Toy : public Product {
protected:
    std::string barcode;
    int ageLimit;
public:
    Toy(const std::string& n, double p, const std::string& bc, int age);
    void Show() const override;
};



class MolochProduct : virtual public Product {
protected:
    std::string expiryDate;
public:
    MolochProduct(const std::string& n, double p, const std::string& exp);
    void Show() const override;
};


#endif // CLASS_H
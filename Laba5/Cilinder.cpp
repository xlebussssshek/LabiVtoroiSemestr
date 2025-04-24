#include <iostream>
using namespace std;
#include "cilinder.h"
#include <iomanip>


void shapka()
{
    cout << "x" << setw(5) << "y" << setw(5) << "z" << setw(10) << "r" << setw(10) << "h" << endl;
}

void Cilinder::In(void)
{
    cout << "¬ведите x" << endl;
    cin >> x;
    cout << "¬ведите y" << endl;
    cin >> y;
    cout << "¬ведите z" << endl;
    cin >> z;
    cout << "¬ведите радиус" << endl;
    cin >> r;
    cout << "¬ведите высоту" << endl;
    cin >> h;
}

void Cilinder::Out(void) const
{
    cout << x << setw(5) << y << setw(5) << z << setw(10) << r << setw(10) << h << endl;
}

double Cilinder::Ob(void)
{
    int V;
    V = 3.14 * h * r * r;
    return V;
}

const Cilinder Cilinder::operator+(const Cilinder& C) const
{
    Cilinder Sum;
    Sum.x = x + C.x;
    Sum.y = y + C.y;
    Sum.z = z + C.z;
    Sum.r = r + C.r;
    Sum.h = h + C.h;
    return Sum;
}

const Cilinder Cilinder::operator-(const Cilinder& C) const
{
    Cilinder Sum;
    Sum.x = x - C.x;
    Sum.y = y - C.y;
    Sum.z = z - C.z;
    Sum.r = r - C.r;
    Sum.h = h - C.h;
    return Sum;
}

const Cilinder Cilinder::operator-(double A) const
{
    Cilinder Sum;
    Sum.r = r - A;
    return Sum;
}

const Cilinder& Cilinder::operator=(const Cilinder& C)
{
    if (this == &C)
    {
        return *this;
    }
    x = C.x;
    y = C.y;
    z = C.z;
    r = C.r;
    h = C.h;
    return *this;
}

bool Cilinder::operator>=(double A)
{
    if (this->Ob() >= A)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& out, const Cilinder& C)
{
	out << C.x << setw(5) << C.y << setw(5) << C.z << setw(10) << C.r << setw(10) << C.h;
	return out;
}

istream& operator>>(istream& in, Cilinder& C)
{
	cout << "¬ведите x" << endl;
    in >> C.x;
    cout << "¬ведите y" << endl;
    in >> C.y;
	cout << "¬ведите z" << endl;
    in >> C.z;
	cout << "¬ведите радиус" << endl;
    in >> C.r;
	cout << "¬ведите высоту" << endl;
    in >> C.h;
	return in;
}
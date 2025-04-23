#include <cstdlib>
#ifndef CILINDER_H
#define CILINDER_H
class Cilinder
{
private:
	double r, h, x, y, z;
public:
	void In();
	void Out() const;
	double Ob();
	const Cilinder operator+(const Cilinder& C)const;
	const Cilinder operator-(const Cilinder& C)const;
	const Cilinder operator-(double A)const;
	const Cilinder& operator=(const Cilinder& C);
	bool operator>= (double A);
	Cilinder() : x(rand() % 20), y(rand() % 20), z(rand() % 20), r((rand() % 200) * 0.12), h(rand() % 200) {}
	Cilinder(double myX, double myY, double myZ, double myR, double myH) : x(myX), y(myY), z(myZ), r(myR), h(myH) {}
	Cilinder(const Cilinder& C) : x(C.x), y(C.y), z(C.z), r(C.r), h(C.h) {}
	~Cilinder() {}
};

void shapka();
#endif // !"CILINDER_H"
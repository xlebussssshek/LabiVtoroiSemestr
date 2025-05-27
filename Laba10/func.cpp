#include <iostream>
using namespace std;
#include "mass.h"

const MyMass& MyMass::operator=(const MyMass& other)
{
	if (this != &other)
	{
		delete[] data;
		size = other.size;
		data = new double[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	return *this;
}

MyMass& MyMass::operator+=(const MyMass& other)
{
	if (size > other.size)
	{
		for (int i = 0; i < other.size; i++)
		{
			data[i] += other.data[i];
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			data[i] += other.data[i];
		}
	}
	return *this;
}

MyMass MyMass::operator+(const MyMass& other) const
{
	MyMass result(size + other.size);
	for (int i = 0; i < size; i++)
	{
		result.data[i] = data[i];
	}
	for (int i = 0; i < other.size; i++)
	{
		result.data[i + size] = other.data[i];
	}
	return result;
}

ostream& operator<<(ostream& out, const MyMass& mass)
{
	out << "Size: " << mass.size << std::endl;
	out << "[";
	for (int i = 0; i < mass.size; i++)
	{
		out << mass.data[i] << " ";
	}
	out << "]" << std::endl;
	return out;
}

istream& operator>>(istream& in, MyMass& mass)
{
	if (mass.size == 0)
	{
		std::cout << "¬ведите размер" << std::endl;
		std::cin >> mass.size;
		mass.data = new double[mass.size];
	}
	std::cout << "¬ведите числа массива" << std::endl;
	for (int i = 0; i < mass.size; i++)
	{
		std::cin >> mass.data[i];
	}
	return in;
}

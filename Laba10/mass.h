#ifndef MASS_H
#define MASS_H
class MyMass
{
private:
	int size;
	double* data;
public:
	const MyMass& operator=(const MyMass& other);
	MyMass& operator+=(const MyMass& other);
	MyMass operator+(const MyMass& other) const;

	friend std::ostream& operator<<(std::ostream& out, const MyMass& mass);
	friend std::istream& operator>>(std::istream& in, MyMass& mass);


	MyMass() : size(0), data(new double[1]) {}
	MyMass(int s) : size(s), data(new double[s]) {}
	MyMass(const MyMass& other)
	{
		size = other.size;
		data = new double[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
		}
	}
	~MyMass()
	{
		delete[] data;
		data = NULL;
	}
};
#endif // !MASS_H

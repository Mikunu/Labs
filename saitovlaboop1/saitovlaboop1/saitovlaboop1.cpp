#include <iostream>
#include <windows.h>

class Vector
{
private:
	double x, y, z;

public:
	void set_vector(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	double get_square()
	{
		return x * x + y * y + z * z;
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double x, y, z;
	std::cout << "Введите x: ";
	std::cin >> x;
	std::cout << "Введите y: ";
	std::cin >> y;
	std::cout << "Введите z: ";
	std::cin >> z;

	Vector vec3;
	vec3.set_vector(x, y, z);
	std::cout << "Квадрат вектора: " << vec3.get_square();

	return 0;
}
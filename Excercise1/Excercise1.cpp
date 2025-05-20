#include <iostream>
#include <string>

class Figure
{
protected:
	int sides;
	std::string name;

public:
	int get_sides()
	{
		return sides;
	}
	std::string get_name()
	{
		return name;
	}
	Figure() : sides(0), name("Фигура") {}
};

class Triangle : public Figure
{
public:
	Triangle() {
		sides = 3;
		name = "Треугольник";
	}
};

class Rectangle : public Figure
{
public:
	Rectangle() {
		sides = 4;
		name = "Четырёхугольник";
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Figure F1;
	Triangle T1;
	Rectangle R1;

	std::cout << "Количество сторон: " << std::endl;
	std::cout << F1.get_name() << ": " << F1.get_sides() << std::endl;
	std::cout << T1.get_name() << ": " << T1.get_sides() << std::endl;
	std::cout << R1.get_name() << ": " << R1.get_sides() << std::endl;

	return 0;
}

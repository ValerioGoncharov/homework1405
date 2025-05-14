#include <iostream>
#include <string>

class Figure
{
private:
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
	Figure(int s, std::string n) : sides(s), name(n) {}
};

class Triangle : public Figure
{
public:
	Triangle(int s, std::string n) : Figure(s, n) {}
};

class Rectangle : public Figure
{
public:
	Rectangle(int s, std::string n) : Figure(s, n) {}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	Figure F1(0, "Фигура");
	Triangle T1(3, "Треугольник");
	Rectangle R1(4, "Четырёхугольник");

	std::cout << "Количество сторон: " << std::endl;
	std::cout << F1.get_name() << ": " << F1.get_sides() << std::endl;
	std::cout << T1.get_name() << ": " << T1.get_sides() << std::endl;
	std::cout << R1.get_name() << ": " << R1.get_sides() << std::endl;

	return 0;
}

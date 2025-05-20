#include <iostream>
#include <string>
#include <cmath>

class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure() : sides_count(0), name("Фигура") {}
    virtual ~Figure() = default;

    virtual void print_info() {
        std::cout << "\n" << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
    }

    virtual bool check() {
        return sides_count == 0;
    }
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle() : a(10), b(20), c(30), A(50), B(60), C(70) {
        sides_count = 3;
        name = "Треугольник";
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }

    bool check() override {
        return (A + B + C) == 180;
    }
};

class RightTriangle : public Triangle {
public:
    RightTriangle() {
        c = sqrt(a * a + b * b);
        C = 90;
        name = "Прямоугольный треугольник";
    }

    bool check() override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() {
        c = a;
        C = A;
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() {
        b = a; c = a;
        A = 60; B = 60; C = 60;
        name = "Равносторонний треугольник";
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrilateral() : a(10), b(20), c(30), d(40), A(50), B(60), C(70), D(80) {
        sides_count = 4;
        name = "Четырёхугольник";
    }

    void print_info() override {
        Figure::print_info();
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

    bool check() override {
        return (A + B + C + D) == 360;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle() {
        c = a; d = b;
        A = 90; B = 90; C = 90; D = 90;
        name = "Прямоугольник";
    }
};

class Square : public Rectangle {
public:
    Square() {
        b = a; c = a; d = a;
        name = "Квадрат";
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() {
        c = a; d = b;
        C = A; D = B;
        name = "Параллелограмм";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() {
        b = a; c = a; d = a;
        name = "Ромб";
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    RightTriangle right_triangle;
    IsoscelesTriangle isosceles_triangle;
    EquilateralTriangle equilateral_triangle;
    Quadrilateral quadrilateral;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhombus rhombus;

    figure.print_info();
    triangle.print_info();
    right_triangle.print_info();
    isosceles_triangle.print_info();
    equilateral_triangle.print_info();
    quadrilateral.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhombus.print_info();

    return 0;
}
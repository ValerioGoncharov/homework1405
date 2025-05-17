#include <iostream>
#include <string>

// создаю метакласс 
class Figure {
protected:
    int sides_count;
    std::string name;

public:
    Figure(int count, std::string n) : sides_count(count), name(n) {}
    virtual ~Figure() = default;
    Figure() : sides_count(0), name("Фигура") {}
	// метод проверки фигуры на правильность
    virtual void print_info() {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n\n";
    }

    virtual bool check() {
        return sides_count == 0;
    }
};

//добавляю базовые классы для треугольников и четырехугольников
class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
    std::string name;

public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name)
        : a(a), b(b), c(c), A(A), B(B), C(C), name(name) {
    }

    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }

    bool check() override {
        return (A + B + C) == 180;
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), name(name) {
    }

    void print_info() override {
        std::cout << name << ":\n";
        std::cout << (check() ? "Правильная" : "Неправильная") << "\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }

    bool check() override {
        return (A + B + C + D) == 360;
    }
};

//добавляю спец классы для треугольников и четырехугольников

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
    }

    bool check() override {
        return Triangle::check() && (C == 90);
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {
    }

    bool check() override {
        return Triangle::check() && (a == c) && (A == C);
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
    }

    bool check() override {
        return Triangle::check() && (a == b && b == c) && (A == 60 && B == 60 && C == 60);
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {
    }

    bool check() override {
        return Quadrilateral::check() &&
            (a == c && b == d) &&
            (A == 90 && B == 90 && C == 90 && D == 90);
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) { name = "Квадрат"; }

    bool check() override {
        return Rectangle::check() && (a == b && b == c && c == d);
    }
};


class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B, "Параллелограмм") {
    }

    bool check() override {
        return Quadrilateral::check() &&
            (a == c && b == d) &&
            (A == C && B == D);
    }
};


class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }

    bool check() override {
        return Parallelogram::check() && (a == b && b == c && c == d);
    }
};



int main() {
    setlocale(LC_ALL, "Russian");
    // Создаю все фигуры по очереди
    Figure figure(0, "Фигура");
    Triangle triangle(10, 20, 30, 50, 60, 70, "Треугольник");
    RightTriangle right_triangle1(10, 20, 30, 50, 60);
    RightTriangle right_triangle2(10, 20, 30, 50, 40);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);
    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80, "Четырёхугольник");
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    // Вывожу информацию о каждой фигуре
    figure.print_info();
    triangle.print_info();
    right_triangle1.print_info();
    right_triangle2.print_info();
    isosceles_triangle.print_info();
    equilateral_triangle.print_info();
    quadrilateral.print_info();
    rectangle.print_info();
    square.print_info();
    parallelogram.print_info();
    rhombus.print_info();

    return 0;
}

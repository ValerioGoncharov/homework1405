#include <iostream>
#include <string>

//добавляю базовые классы для треугольников и четырехугольников
class Triangle {
protected:
    int a, b, c;
    int A, B, C;
    std::string name;

public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name)
        : a(a), b(b), c(c), A(A), B(B), C(C), name(name) {
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    std::string get_name() { return name; }
};

class Quadrilateral {
protected:
    int a, b, c, d;
    int A, B, C, D;
    std::string name;

public:
    Quadrilateral(int a, int b, int c, int d, int A, int B, int C, int D, std::string name)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D), name(name) {
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    std::string get_name() { return name; }
};

//добавляю спец классы для треугольников и четырехугольников

class RightTriangle : public Triangle {
public:
    RightTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90, "Прямоугольный треугольник") {
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A, "Равнобедренный треугольник") {
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60, "Равносторонний треугольник") {
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle(int a, int b)
        : Quadrilateral(a, b, a, b, 90, 90, 90, 90, "Прямоугольник") {
    }
};

class Square : public Rectangle {
public:
    Square(int a) : Rectangle(a, a) { name = "Квадрат"; }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrilateral(a, b, a, b, A, B, A, B, "Параллелограмм") {
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {
        name = "Ромб";
    }
};

// Функции для вывода информации
void print_info(Triangle* figure) {
    std::cout << figure->get_name() << ":\n";
    std::cout << "Стороны: a=" << figure->get_a() << " b=" << figure->get_b()
        << " c=" << figure->get_c() << "\n";
    std::cout << "Углы: A=" << figure->get_A() << " B=" << figure->get_B()
        << " C=" << figure->get_C() << "\n\n";
}

void print_info(Quadrilateral* figure) {
    std::cout << figure->get_name() << ":\n";
    std::cout << "Стороны: a=" << figure->get_a() << " b=" << figure->get_b()
        << " c=" << figure->get_c() << " d=" << figure->get_d() << "\n";
    std::cout << "Углы: A=" << figure->get_A() << " B=" << figure->get_B()
        << " C=" << figure->get_C() << " D=" << figure->get_D() << "\n\n";
}

int main() {
	setlocale(LC_ALL, "Russian");
    // Создаю все фигуры по очереди
    Triangle triangle(10, 20, 30, 50, 60, 70, "Треугольник");
    RightTriangle right_triangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isosceles_triangle(10, 20, 50, 60);
    EquilateralTriangle equilateral_triangle(30);

    Quadrilateral quadrilateral(10, 20, 30, 40, 50, 60, 70, 80, "Четырёхугольник");
    Rectangle rectangle(10, 20);
    Square square(20);
    Parallelogram parallelogram(20, 30, 30, 40);
    Rhombus rhombus(30, 30, 40);

    // Вывожу информацию о каждой фигуре
    print_info(&triangle);
    print_info(&right_triangle);
    print_info(&isosceles_triangle);
    print_info(&equilateral_triangle);

    print_info(&quadrilateral);
    print_info(&rectangle);
    print_info(&square);
    print_info(&parallelogram);
    print_info(&rhombus);

    return 0;
}
#include <iostream>
#include <string>

class Figure {
protected:
    std::string name;  // Имя фигуры (неизменяемое)
    int sides_count; // Количество сторон

public:
    std::string get_name() const { return name; }
    int get_sides_count() const { return sides_count; }
    virtual void print_info() const = 0;  // Виртуальная функция
    virtual ~Figure() {}  // Виртуальный деструктор
};

//добавляю базовые классы для треугольников и четырехугольников
class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
   

public:
    Triangle() {  // Конструктор без параметров
        name = "Треугольник";
        sides_count = 3;
        a = 10; b = 20; c = 30;  // Задаю стороны внутри
        A = 50; B = 60; C = 70;  // Задаю углы внутри
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    void print_info() const override {
        std::cout << name << ":\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Quadrilateral : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
  

public:
    Quadrilateral() {  
        name = "Четырёхугольник";
        sides_count = 4;
        a = 10; b = 20; c = 30; d = 40;
        A = 50; B = 60; C = 70; D = 80;
    }

    int get_a() { return a; }
    int get_b() { return b; }
    int get_c() { return c; }
    int get_d() { return d; }
    int get_A() { return A; }
    int get_B() { return B; }
    int get_C() { return C; }
    int get_D() { return D; }
    
    void print_info() const override {
        std::cout << name << ":\n";
        std::cout << "Количество сторон: " << sides_count << "\n";
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};

//добавляю спец классы для треугольников и четырехугольников

class RightTriangle : public Triangle {
public:
    RightTriangle() {
        name = "Прямоугольный треугольник";
        C = 90;
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle() {
        name = "Равнобедренный треугольник";
        a = c;
        A = C;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle() {
        name = "Равносторонний треугольник";
        a = b = c;
        A = B = C;
    }
};

class Rectangle : public Quadrilateral {
public:
    Rectangle() {  
        name = "Прямоугольник";
        a = c; b = d;  
        A = B = C = D = 90;  
    }
};

class Square : public Rectangle {
public:
    Square() {  
        name = "Квадрат";
        a = b = c = d;  
    }
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram() {
        name = "Параллелограмм";
        a = c = 20;
        b = d = 30;
        A = C = 30;
        B = D = 40;
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus() {
        name = "Ромб";
        a = b = c = d = 30;
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
    Triangle triangle;
    RightTriangle right_triangle;
    IsoscelesTriangle isosceles_triangle;
    EquilateralTriangle equilateral_triangle;

    Quadrilateral quadrilateral;
    Rectangle rectangle;
    Square square;
    Parallelogram parallelogram;
    Rhombus rhombus;

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
#include <iostream>
#include <string>
#include <cmath>

class Point {
public:
    int x, y;
    std::string name;

    Point() : x(0), y(0), name("Default") {}

    Point(int x, int y, const std::string& name) : x(x), y(y), name(name) {}

    int getX() const { return x; }
    int getY() const { return y; }
    std::string getName() const { return name; }
};

class Figure {
public:
    double GetSideLength(const Point& A, const Point& B) {
        return sqrt(pow(B.getX() - A.getX(), 2) + pow(B.getY() - A.getY(), 2));
    }

    void CalculatePerimeter() {
        double perimeter = 0.0;

        if (numPoints == 3) {
            perimeter += GetSideLength(point1, point2);
            perimeter += GetSideLength(point2, point3);
            perimeter += GetSideLength(point3, point1);
        }
        else if (numPoints == 4) {
            perimeter += GetSideLength(point1, point2);
            perimeter += GetSideLength(point2, point3);
            perimeter += GetSideLength(point3, point4);
            perimeter += GetSideLength(point4, point1);
        }
        else if (numPoints == 5) {
            perimeter += GetSideLength(point1, point2);
            perimeter += GetSideLength(point2, point3);
            perimeter += GetSideLength(point3, point4);
            perimeter += GetSideLength(point4, point5);
            perimeter += GetSideLength(point5, point1);
        }

        std::cout << "Perimeter: " << perimeter << std::endl;
    }

    Figure(const Point& p1, const Point& p2, const Point& p3) : numPoints(3), point1(p1), point2(p2), point3(p3) {}
    Figure(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : numPoints(4), point1(p1), point2(p2), point3(p3), point4(p4) {}
    Figure(const Point& p1, const Point& p2, const Point& p3, const Point& p4, const Point& p5) : numPoints(5), point1(p1), point2(p2), point3(p3), point4(p4), point5(p5) {}

private:
    int numPoints;
    Point point1, point2, point3, point4, point5;
};

int main() {
    Point p1(1, 2, "A");
    Point p2(3, 4, "B");
    Point p3(5, 6, "C");

    Figure f1(p1, p2, p3);
    f1.CalculatePerimeter();

    return 0;
}

#include <vector>
#include <iostream>
#include <cmath>


class Point {
public:
    virtual void draw() const = 0; 
    virtual void remove() const = 0; 
    virtual void move(double dx, double dy) = 0; 
    virtual void rotate(double angle) = 0; 
};


class Dot : public Point {
private:
    double x, y;
public:
    Dot(double x, double y) : x(x), y(y) {}

    void draw() const override {
        std::cout << "Draw a point at coordinates (" << x << ", " << y << ")" << std::endl;
    }

    void remove() const override {
        std::cout << "Remove the point at coordinates (" << x << ", " << y << ")" << std::endl;
    }

    void move(double dx, double dy) override {
        x += dx;
        y += dy;
        std::cout << "Move the point to new coordinates (" << x << ", " << y << ")" << std::endl;
    }

    void rotate(double angle) override {
        double new_x = x * cos(angle) - y * sin(angle);
        double new_y = x * sin(angle) + y * cos(angle);
        x = new_x;
        y = new_y;
        std::cout << "Rotate the point to new coordinates (" << x << ", " << y << ")" << std::endl;
    }
};


class Line : public Point {
private:
    Dot start, end;
public:
    Line(double x1, double y1, double x2, double y2) : start(x1, y1), end(x2, y2) {}

    void draw() const override {
        start.draw();
        end.draw();
        std::cout << "Draw a line between the points" << std::endl;
    }

    void remove() const override {
        start.remove();
        end.remove();
        std::cout << "Remove the line" << std::endl;
    }

    void move(double dx, double dy) override {
        start.move(dx, dy);
        end.move(dx, dy);
        std::cout << "Move the line" << std::endl;
    }

    void rotate(double angle) override {
        start.rotate(angle);
        end.rotate(angle);
        std::cout << "Rotate the line" << std::endl;
    }
};


class Quadrilateral : public Point {
protected:
    Dot upperLeft, upperRight, lowerLeft, lowerRight;
public:
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
        : upperLeft(x1, y1), upperRight(x2, y2), lowerLeft(x3, y3), lowerRight(x4, y4) {}

    virtual void draw() const = 0;
    virtual void remove() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void rotate(double angle) = 0;
};


class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double x1, double y1, double x2, double y2, double height)
        : Quadrilateral(x1, y1, x2, y2, x1 + height, y1, x2 + height, y2) {}

    void draw() const override {
        upperLeft.draw();
        upperRight.draw();
        lowerLeft.draw();
        lowerRight.draw();
        std::cout << "Draw a parallelogram" << std::endl;
    }

    void remove() const override {
        upperLeft.remove();
        upperRight.remove();
        lowerLeft.remove();
        lowerRight.remove();
        std::cout << "Remove the parallelogram" << std::endl;
    }

    void move(double dx, double dy) override {
        upperLeft.move(dx, dy);
        upperRight.move(dx, dy);
        lowerLeft.move(dx, dy);
        lowerRight.move(dx, dy);
        std::cout << "Move the parallelogram" << std::endl;
    }

    void rotate(double angle) override {
        upperLeft.rotate(angle);
        upperRight.rotate(angle);
        lowerLeft.rotate(angle);
        lowerRight.rotate(angle);
        std::cout << "Rotate the parallelogram" << std::endl;
    }
};


class Rectangle : public Quadrilateral {
public:
    Rectangle(double x1, double y1, double width, double height)
        : Quadrilateral(x1, y1, x1 + width, y1, x1, y1 + height, x1 + width, y1 + height) {}

    void draw() const override {
        upperLeft.draw();
        upperRight.draw();
        lowerLeft.draw();
        lowerRight.draw();
        std::cout << "Draw a rectangle" << std::endl;
    }

    void remove() const override {
        upperLeft.remove();
        upperRight.remove();
        lowerLeft.remove();
        lowerRight.remove();
        std::cout << "Remove the rectangle" << std::endl;
    }

    void move(double dx, double dy) override {
        upperLeft.move(dx, dy);
        upperRight.move(dx, dy);
        lowerLeft.move(dx, dy);
        lowerRight.move(dx, dy);
        std::cout << "Move the rectangle" << std::endl;
    }

    void rotate(double angle) override {
        upperLeft.rotate(angle);
        upperRight.rotate(angle);
        lowerLeft.rotate(angle);
        lowerRight.rotate(angle);
        std::cout << "Rotate the rectangle" << std::endl;
    }
};


class Rhombus : public Quadrilateral {
public:
    Rhombus(double x, double y, double side, double angle)
        : Quadrilateral(x, y, x + side, y, x, y + side, x + side, y + side) {
        
        upperLeft.rotate(angle);
        upperRight.rotate(angle);
        lowerLeft.rotate(angle);
        lowerRight.rotate(angle);
    }

    void draw() const override {
        upperLeft.draw();
        upperRight.draw();
        lowerLeft.draw();
        lowerRight.draw();
        std::cout << "Draw a rhombus" << std::endl;
    }

    void remove() const override {
        upperLeft.remove();
        upperRight.remove();
        lowerLeft.remove();
        lowerRight.remove();
        std::cout << "Remove the rhombus" << std::endl;
    }

    void move(double dx, double dy) override {
        upperLeft.move(dx, dy);
        upperRight.move(dx, dy);
        lowerLeft.move(dx, dy);
        lowerRight.move(dx, dy);
        std::cout << "Move the rhombus" << std::endl;
    }

    void rotate(double angle) override {
        upperLeft.rotate(angle);
        upperRight.rotate(angle);
        lowerLeft.rotate(angle);
        lowerRight.rotate(angle);
        std::cout << "Rotate the rhombus" << std::endl;
    }
};


class Square : public Point {
private:
    Dot upperLeft, upperRight, lowerLeft, lowerRight;
public:
    Square(double x, double y, double side)
        : upperLeft(x, y), upperRight(x + side, y), lowerLeft(x, y + side), lowerRight(x + side, y + side) {}

    void draw() const override {
        upperLeft.draw();
        upperRight.draw();
        lowerLeft.draw();
        lowerRight.draw();
        std::cout << "Draw a square" << std::endl;
    }

    void remove() const override {
        upperLeft.remove();
        upperRight.remove();
        lowerLeft.remove();
        lowerRight.remove();
        std::cout << "Remove the square" << std::endl;
    }

    void move(double dx, double dy) override {
        upperLeft.move(dx, dy);
        upperRight.move(dx, dy);
        lowerLeft.move(dx, dy);
        lowerRight.move(dx, dy);
        std::cout << "Move the square" << std::endl;
    }

    void rotate(double angle) override {
        upperLeft.rotate(angle);
        upperRight.rotate(angle);
        lowerLeft.rotate(angle);
        lowerRight.rotate(angle);
        std::cout << "Rotate the square" << std::endl;
    }
};

int main() {
    std::vector<Point*> shapes; 

    
    shapes.push_back(new Dot(0.0, 0.0));
    shapes.push_back(new Square(2.0, 2.0, 4.0));

    
    for (const auto& shape : shapes) {
        shape->draw();
    }

    
    for (const auto& shape : shapes) {
        shape->move(1.0, 1.0);
    }

    
    for (const auto& shape : shapes) {
        shape->rotate(3.14 / 4);
    }

    
    for (const auto& shape : shapes) {
        shape->remove();
        delete shape; 
    }

    return 0;
}
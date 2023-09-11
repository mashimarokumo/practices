#include <iostream>
using namespace std;
// 基类 Shape
class Shape{
    public:
        virtual double calculateArea(){return 0;}
        virtual ~Shape(){};
};

// 派生类 Circle
class Circle : public Shape{
    private: 
    double radius;
    
    public:
    Circle(double a){
        radius = a;
    }
    virtual double calculateArea(){
        return 3.14159 * radius * radius;
    }
};

// 派生类 Rectangle
class Rectangle : public Shape{
    private:
    double width;
    double height;

    public:
    Rectangle(double w, double h){
        width = w;height = h;
    }
    virtual double calculateArea(){
        return width*height;
    }
};

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    Shape* shape1 = new Circle(a);
    Shape* shape2 = new Rectangle(b, c);

    cout << "Area of shape1: " << shape1->calculateArea() << endl;
    cout << "Area of shape2: " << shape2->calculateArea() << endl;

    delete shape1;
    delete shape2;

    return 0;
}



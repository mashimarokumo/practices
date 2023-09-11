#include  <iostream>
using  namespace  std;

class Point{
private:
    int x, y;
    public:
    	Point(){}
        Point(int a, int b){
            x=a;
            y=b;
        }
        int getPx(){
            return x;
        }
        int getPy(){
            return y;
        }

};

class Rectangle:public Point{
private:
    Point pr;
public:
	Rectangle(int a, int b, int c, int d):Point(a, b){
		pr= Point(c,d);
	}
    int Area(){
        return (pr.getPx()-getPx())*(pr.getPy()-getPy());
    }
};

class Circle:public Point{
private:
    Point pc;
public:
	Circle(int a, int b, int c, int d):Point(a, b){
		pc= Point(c,d);
	}
    int Area(){
        float rf = (pc.getPx()-getPx())*(pc.getPx()-getPx()) + (pc.getPy()-getPy())*(pc.getPy()-getPy());
        return int(rf * 3);
    }
};

int  main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    Rectangle rec(a,b,c,d); //使用构造函数初始化
    cout << rec.Area() << endl;

    cin >> a >> b >> c >> d;
    Circle cir(a,b,c,d);      
    cout << cir.Area() << endl;
    
    return  0;
}


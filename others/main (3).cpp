#include <iostream>
#include <string>
using namespace std;
class Student {
    const string name;
    int grade;
public:
//构造函数
    Student(string a, int b):name(a){grade = b;}
//print函数
    void print()const{cout << name << ": " << grade << endl;}
};
int main() {
    const Student stu = Student("lily", 90);   //定义常对象stu
    stu.print();
    return 0;
 }



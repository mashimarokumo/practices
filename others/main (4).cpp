#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Student{
private:
    string name;
public:
    void setStu(string s){name = s;}
    void print() //定义常函数print()
    {cout << name << endl;}    
};
int main()
{
    string str;
    cin >> str;
    Student s;
    s.setStu(str);
    Student *ps = &s; //指向对象的指针
    ps->print(); //调用print函数
    //定义指向成员函数的指针pf, 指向print()
    void(Student::*pf)();
    pf = &Student::print;
    (s.*pf)(); //通过pf调用print()成员
    return 0;
}


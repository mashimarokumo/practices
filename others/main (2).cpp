#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Student{
private:
    string name;
    static int countS; //记录目前存在的Student对象个数，生成+1，消失-1
public:    
    Student(){countS += 1;} //通过构造函数修改 countS
    ~Student(){countS -= 1;} //通过析构函数修改 countS
    void setStu(string s){name = s;}
   //定义静态函数print，输出name和countS
   static void print(Student s){ cout << s.name << " " << countS << endl;} 
};
int Student::countS = 0;; //countS 类外初始化为0
int main()
{
    Student s1;
    Student s2;
    s2.setStu("lily");
    Student::print(s2);    //调用print函数
    return 0;
}


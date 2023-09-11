#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Student{
private:
    string name;
public:
    void setStu(string s){name = s;}
    void print(){cout << name << endl;}
    //声明并定义友元函数compare，使用Student对象的常引用做形参a 和 b
    friend bool compare(const Student a, const Student b){
        return a.name < b.name;
    }
};
bool compare(const Student a, const Student b); //声明compare
int main()
{
    int n;
    cin >> n;
    vector<Student> stu(n); //动态数组vector，和普通数组使用方法相同，可通过下标访问元素
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        stu[i].setStu(str); //将str存为stu[i]的name中
    }
    sort(stu.begin(),stu.end(),compare); //使用友元函数排序
    for(int i = 0; i < n; i++){
        stu[i].print(); //将stu[i]的name输出
    }

    system("pause");
    return 0;
}


#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//声明模板类Number，类中只有一个数据成员num
template <class T>
class Number{
private:
    T  num;
public:
    void setNum(T n){num = n;} //设置num值
    void getNum(){cout << num << endl;}
    T add(T  n){return num+n;} //设计函数add完成+操作
};
int main()
{
    int i, j;
    cin >> i >> j;
    Number<int> n; //用int定义模板类对象n
    n.setNum(i);
    cout << n.add(j) << endl;
    string si, sj;
    cin >> si >> sj;
    Number<string> ns; //用string定义模板类对象ns
    ns.setNum(si);
    cout << ns.add(sj) << endl;
    return 0;
}


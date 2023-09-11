// Example program
#include <iostream>
//#include <string.h>//特意注释掉的，纯手工实现
using namespace std;
class String { 
public:
   String(){ p=NULL; len = 0;}
   String( char *str ) {p=str; }
   void display() {cout<<p<<endl;}    
   // 声明和定义重载运算符 >>和<<
   friend istream& operator >> (istream& cin,String& s)
       {
           char arr[100];
           cin >> arr;
           String a(arr);
           s = String(a);
           return cin;
       }
   friend ostream& operator << (ostream& cout, String& s)
       {
           cout << s.p << endl;
           return cout;
       }

private:
   char *p;
   int len;
};


int main() {
  String string1;
  cin >> string1;
  cout << string1;
  return 0;
}



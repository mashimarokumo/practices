#include <iostream>
//#include <string.h> //特意注释掉的，纯手工实现
using namespace std;
class String { 
public:
   String(){ p=NULL; len = 0;}
   String( char *str ) {p=str; len = getLen();}
   void display() {cout<<p<<endl;} 
   int getLen(){
       int le = 0;
       while(this -> p[le]){
         le++;
       }
       return le;
   }
   //使用友元函数或成员函数，实现+重载，类内定义和声明
    friend String operator +(String& s,String& m)
       {
           int nlen = s.getLen() + m.getLen();
           char* sum = new char[nlen+1];
           for (int i = 0; i < s.getLen(); ++i)
           {
   
               sum[i] = s.p[i];
               
           }
           for (int j = s.getLen(),i=0; j < nlen; ++j)
           {
               
               sum[j] = m.p[i];
               i++;
   
           }
           sum[nlen] = '\0';
           String ret(sum);
           return ret;
       }

private:
   char *p;
   int len;
};


int main() {
  char s1[10], s2[10];
  cin >> s1 >> s2;
  String string1(s1), string2(s2);
  String string3 = string1 + string2; // + 调用重载运算符
  string3.display();
  string1.display();
  return 0;
}




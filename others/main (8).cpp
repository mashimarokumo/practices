// Example program
#include <iostream>
//#include <string.h>//特意注释掉的，纯手工实现
using namespace std;
class String { 
public:
   String(){ p=NULL; len = 0;}
   String( char *str ) {p=str; }
   void display() {cout<<p<<endl;} 
   int getLen(){
       int le = 0;
       while(this -> p[le]){
         le++;
       }
       return le; 
   }
   char* getP(){return p;}
   
  //类内定义和声明重载的“+”
  friend String operator +(String s, char m1)
      {
          String m = String(&m1);
          m.len = 1;
          int nlen = s.getLen() + 1;
          char* sum = new char[nlen + 1];
          for (int i = 0; i < s.getLen(); ++i)
          {
             sum[i] = s.p[i];
              //sum = m.getP();
          }
          for (int j = s.getLen(), i = 0; j < nlen; ++j)
          {
              sum[j] = m.p[i];
              i++;
          }
          sum[nlen] = '\0';
          String ret(sum);
          return ret;
      }
      friend String operator +(char s1, String m)
      {
          String s = String(&s1);
          s.len = 1;
          int nlen = 1 + m.getLen();
          char* sum = new char[nlen + 1];
          for (int i = 0; i < s.getLen(); ++i)
          {
              sum[i] = s.p[i];
          }
          for (int j = s.getLen(), i = 0; j < nlen; ++j)
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
  char s1[10], c;
  cin >> s1 >> c;
  //cout << "+" << s1 << "+" << c << "+"<<endl;
  String string1(s1);
  String string2 = string1 + c;
  string2.display();
  string2 = c + string1;
  string2.display();
  string1.display();
  return 0;
}



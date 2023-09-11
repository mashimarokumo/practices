// Example program
#include <iostream>
using namespace std;

class Complex {
public:
  Complex(){real=0;imag=0;}
  Complex(double r,double i)
  {real=r;imag=i;}
//运算符重载
  Complex(double& r){
      real = r; imag = 0;
  }
   friend Complex operator + (Complex c1, Complex c2) { return Complex(c1.real + c2.real, c1.imag + c2.imag); }

  void display(){
    cout << "(" << this->real << this->imag << "i)" << endl;
  }
private:
  double real;
  double imag;
};


int main() {
  double r,i;
  cin >> r >> i;
  double j;
  cin >> j;

  Complex c1(r,i), c;  
  c=c1+j;
  c.display();
  c=j+c1; //交换律
  c.display();
  return 0;
}



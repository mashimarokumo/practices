#include <iostream>
#include <string>
using namespace std;
// 虚基类 Person
class Person{
    protected:
    string name;

    public:
    virtual void introduce(){
        cout << "My name is " << name << ". " << endl;
    };
    virtual ~Person(){};
};


// 虚基类 Student，继承自 Person
class Student : virtual public Person{
    protected:
    int studentID;

    public:
    virtual void introduce(){
        cout << "My name is " << name << ". " << endl;cout << "I am a student. My student ID is " << studentID << "." << endl;
    }
};

// 虚基类 Employee，继承自 Person
class Emplyee : virtual public Person{
    protected:
    string company;

    public:
    virtual void introduce(){
cout << "My name is " << name << ". " << endl;cout << "I am an employee. I work at " << company << "." << endl;
    }
};


// 派生类 TeachingAssistant，同时继承 Student 和 Employee
class TeachingAssistant : public Student, public Emplyee{
    public:
    TeachingAssistant(string a, int c, string b){
        name = a;
        company = b;
        studentID = c;
    }
    virtual void introduce()
   { // introduce函数 函数体
         cout << "My name is " << name << ". " << endl;
        cout << "I am a teaching assistant. I work at " << company << " and my student ID is " << studentID << "." <<endl;
    }
};
int main() {
    string a, b;
    int c;
    cin >> a>>c>>b;
    TeachingAssistant ta(a, c, b);
    ta.introduce();

    return 0;
}



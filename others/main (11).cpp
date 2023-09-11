#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

class Personnel{
    // private? 还是 protected? 
    protected:
        string Pname;
        string Pnum;
        vector<string> Pcour;
    public:
        // 构造函数
        Personnel(){
                        	
        				}
        ~Personnel(){
            Pcour.clear();
        }
        // 其他成员函数，可填可不填
        
};

class Course{
    private:
        string Cname;
        int Cscore;
        map<string, double> Cstu_score; //记录某学生对应的成绩
    public:
        // 构造函数
        Course(string name, int score, map<string,  double> smap){
        					Cname = name;
        					Cscore = score;
        					Cstu_score = smap;
        				}
        ~Course(){
            Cstu_score.clear();
        }
        int getCscore(){return Cscore;}
        double stu_score(string stu_num) //通过学号找到成绩
        {return Cstu_score[stu_num];}

        // 其他成员函数，可填可不填
        
};

vector<Course> COU;
map<string, int> cou_id; //记录课程编号，即在COU中的下标

class Student: public Personnel{
    private:
        double gpa;
    public:
        // 构造函数
        Student(string name, string num, vector<string> cour, double g){
        					Pname = name;
        					Pnum = num;
        					Pcour = cour;
        					gpa = g;
        				}
        double calGPA(){
            int sum = 0;
            gpa = 0.0;
            // 遍历vector<string> Pcour，it本身是个string类型的指针
            for(vector<string>::iterator it = Pcour.begin(); it != Pcour.end(); ++it){
                int couN = cou_id[*it]; //通过课程名称在COU中的索引，获得该课程学分
                int credit = COU[couN].getCscore();

                //通过学生学号获得该课程该学生对应的成绩
                double score =  COU[couN].stu_score(Pnum); 
                // 计算gpa，注意精度
                gpa += double(credit) * (score / 10.0-5.0);
                								sum += credit;
            }
             // 计算gpa
            gpa = gpa / sum;
            						return gpa;
        }
        // 其他成员函数，可填可不填
        string getPname(){
        					return Pname;
        				}
};

class Teacher: public Personnel{
    private:
        int Tscore;
    public:
        // 构造函数
        Teacher(string name, string num, vector<string> cour, double s){
        					Pname = name;
        					Pnum = num;
        					Pcour = cour;
        					Tscore = s;
        				}
        int calTscore(){
            //Tscore = 0;
            // 遍历vector<string> Pcour
            for(vector<string>::iterator it = Pcour.begin(); it != Pcour.end(); ++it){
                int couN = cou_id[*it]; //通过课程名称在COU中的索引，获得该课程学分
                // 计算Tscore
                 Tscore += COU[couN].getCscore();
            }
            return Tscore;
        }
        // 其他成员函数，可填可不填
        
};
int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int a;
    //记录所有学生信息
    vector<Student> stu; //建立一个动态数组，将所有学生信息存进去，以便后续按顺序输出学生信息
    stu.clear(); 
    cin >> a;
    for(int i = 0; i < a; i++){
        string s1, s2;
        int b;
        cin >> s1 >> s2 >> b;
        vector<string> sc;
        sc.clear();
        for(int j = 0; j < b; j++){
            string s3;
            cin >> s3;
            sc.push_back(s3); //push_back成员函数：向vector对象动态数组最后添加元素
        }
        Student s(s1, s2, sc, 0.0); //需要设计对应的构造函数，完成对象建立
        stu.push_back(s);
    }

    //记录所有课程信息
    cin >> a;
    COU.clear();
    for(int i = 0; i < a; i++){
        string s;
        int b, c;
        cin >> s >> b >> c;
        map<string, double> Cstu_score; 
        // map中的每个元素是一对映射，一个string对应一个double，可以通过string的值找到对应的double值
        //例如一个学号对应一个成绩
        for(int j = 0; j < c; j++){
            string stu;
            double d;
            cin >> stu >> d;
            Cstu_score[stu] = d; //map 对象的下标[ ] 是  一对映射的第一个值，即学号
        }
        Course cour(s, b, Cstu_score); //需要设计对应的构造函数，完成对象建立

        COU.push_back(cour);
        cou_id[s] = i;  // 后续可根据 课程名称找到该课程在动态数组COU的下标，方便通过课程名称查找课程信息
    }
    //遍历所有学生，计算他们的gpa
    cout << "Student:\n";
    for(vector<Student>::iterator it = stu.begin(); it != stu.end(); ++it){
    // 通过迭代器遍历动态数组vector，it 本身是Student* 指针类型
        cout << it->getPname() << " " << it->calGPA() << endl;  //需要设计对应的成员函数
    }

    //记录所有老师信息
    //vector<Teacher> tea;
    //tea.clear();
    cin >> a;
    cout << "Teacher:\n";
    for(int i = 0; i < a; i++){
        string s1, s2;
        int b;
        cin >> s1 >> s2 >> b;
        vector<string> sc;
        sc.clear();
        for(int j = 0; j < b; j++){
            string s3;
            cin >> s3;
            sc.push_back(s3);
        }
        Teacher t(s1, s2, sc, 0); //需要设计对应的构造函数，完成对象建立
        cout << s1 << " " << t.calTscore() << endl; //需要设计对应的成员函数
        //tea.push_back(t);
    }

    return 0;
}




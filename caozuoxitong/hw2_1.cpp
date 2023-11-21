#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class pcb { /* 定义进程控制块PCB */
public: 
    string name; 
    char state; 
    int ntime; 
    int rtime; 
    int enterTime;
    int endTime;
    int stTime;
    int longTime;
    float wlongTime;
    float r;
};
typedef pcb PCB; 
vector<PCB*> ps;
vector<PCB*> loadps;
float sum, wsum;

PCB *p;

void sort(pcb *cp) /* 建立对进程进行优先级排列函数*/ 
{ 
    ps.insert(upper_bound(ps.begin(), ps.end(), cp, [](PCB* a, PCB* b){ return a->enterTime < b->enterTime; }), cp);
} 
void input() /* 建立进程控制块函数*/ 
{ 
    int i,num; 
    system("cls"); /*清屏*/

    printf("\n 请输入进程号?"); 
    scanf("%d",&num); 
    for(i=0;i<num;i++) 
    { 
        printf("\n 进程号No.%d:\n",i); 
        pcb *p = new PCB();
        printf("\n 输入进程名:"); 
        cin >> p->name;
        printf("\n 输入进程运行时间:"); 
        scanf("%d",&p->ntime); 
        printf("\n 输入进程到达时间:"); 
        scanf("%d",&p->enterTime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        sort(p); /* 调用sort函数*/ 
    } 
} 
int space() 
{ 
    return ps.size(); 
} 
void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/ 
{ 
    //cout << endl << "进程 [" << p->name << "] 已完成." << endl; 
    printf("\n qname \t startTime \t endTime \t longTime \t wlongTime \n"); 
    cout << "|" << p->name << "\t"; 
    printf("|%d\t\t",p->stTime); 
    printf("|%d\t\t",p->endTime); 
    printf("|%d\t\t",p->longTime); 
    cout << "|" << p->wlongTime << "\t"; 
    printf("\n"); 
    
    free(p); 
} 
void Start(){
    int len,h=0; 
    char ch; 
    len=space(); 
    while((len!=0)&&(!ps.empty())) 
    { 
        int index = 0;

        while (index < ps.size() && ps[index]->enterTime > h)
        {
            index ++;
        }
        if(index < ps.size()){
            p = ps[index];
            //ps.erase(ps.begin() + index);
            p->state='R'; 
            p->stTime = h+1;
            h += p->ntime;
            (p->rtime)+=p->ntime; 
            if(p->rtime==p->ntime) {
                ps.erase(ps.begin() + index);
                p->endTime = h;
                p->longTime = p->endTime - p->enterTime;
                p->wlongTime = (float)p->longTime / (float)p->ntime;

                sum += p->longTime;
                wsum += p->wlongTime;

                destroy(); /* 调用destroy函数*/ 
            }   
            else 
            { 
                h++;
                p->state='w'; 
                //ps.push_back(p);
            } 
        }else{
            p = NULL;
        }
    } 

    
    cout << endl << "进程已经完成." << "平均周转时间为" << sum / (float)len << "平均带权周转时间为" << wsum / (float)len; 
    ch=getchar(); 
    ch=getchar(); 
}

void HRN(){
    int len,h=0; 
    char ch; 
    len=space(); 
    while((len!=0)&&(!ps.empty())) 
    { 
        int index = 0;

        for (int i = 0; i < ps.size(); i++)
        {
            if(ps[i]->enterTime < h){
                ps[i]->r = (float)(ps[i]->ntime + h + 1 -ps[i]->enterTime) / (float)ps[i]->ntime;
            }else ps[i]->r = 0;
        }
        
        sort(ps.begin(), ps.end(), [](PCB* a, PCB* b){ return a->r > b->r; });

        while (index < ps.size() && ps[index]->enterTime > h)
        {
            index ++;
        }
        if(index < ps.size()){
            p = ps[index];
            //ps.erase(ps.begin() + index);
            p->state='R'; 
            p->stTime = h+1;
            h += p->ntime;
            (p->rtime)+=p->ntime; 
            if(p->rtime==p->ntime) {
                ps.erase(ps.begin() + index);
                p->endTime = h;
                p->longTime = p->endTime - p->enterTime;
                p->wlongTime = (float)p->longTime / (float)p->ntime;

                sum += p->longTime;
                wsum += p->wlongTime;

                destroy(); /* 调用destroy函数*/ 
            }   
            else 
            { 
                h++;
                p->state='w'; 
                //ps.push_back(p);
            } 
        }else{
            p = NULL;
        }
    } 

    
    cout << endl << "进程已经完成." << "平均周转时间为" << sum / (float)len << "平均带权周转时间为" << wsum / (float)len; 
    ch=getchar(); 
    ch=getchar(); 
}

vector<PCB*> deepCopy(vector<PCB*> vp){
    vector<PCB*> npv;
    for (auto &&p : vp)
    {
        pcb *np = new pcb();
        np->enterTime = p->enterTime;
        np->name = p->name;        
        np->ntime = p->ntime;
        np->rtime = p->rtime;
        np->state = p->state;

        npv.push_back(np);
    }
    
    return npv;
}

int main(int argc, char const *argv[])
{
    system("chcp 65001");
    
    input(); 
    loadps = deepCopy(ps);
    cout << "-------FCFS---------" << endl;
    Start();

    sum = 0;wsum = 0;
    ps = vector<PCB*>();
    for (auto &&cp : loadps)
    {
        ps.insert(upper_bound(ps.begin(), ps.end(), cp, [](PCB* a, PCB* b){ return a->ntime < b->ntime; }), cp);
    }

    loadps = deepCopy(ps);
    cout << "-------SJF---------" << endl;
    Start();

    sum = 0;wsum = 0;
    ps = vector<PCB*>();
    for (auto &&cp : loadps)
    {
        sort(cp);
    }
    cout << "-------HRN---------" << endl;
    HRN();

    return 0;
}


#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 
#include <vector>
#include <algorithm>
using namespace std;
#define getpch(type) (type*)malloc(sizeof(type)) 

struct pcb { /* 定义进程控制块PCB */ 
    char name[10]; 
    char state; 
    int ntime; 
    int super; 
    int rtime; 
    int enterTime;
};
typedef struct pcb PCB; 
vector<PCB*> ps;

vector<PCB*> psback;
PCB *p;
PCB *rp;

int time = 2400;

void sort(pcb *cp, bool bySuper = true) /* 建立对进程进行优先级排列函数*/ 
{ 
    if(bySuper) ps.insert(upper_bound(ps.begin(), ps.end(), cp, [](PCB* a, PCB* b){ return a->super < b->super || a->super == b->super && a->ntime < b->ntime; }), cp);
    else psback.insert(upper_bound(psback.begin(), psback.end(), cp, [](PCB* a, PCB* b){ return a->ntime < b->ntime; }), cp);
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
        pcb *p = getpch(pcb);
        printf("\n 输入进程名:"); 
        scanf("%s",p->name); 
        printf("\n 输入进程运行时间:"); 
        scanf("%d",&p->ntime); 
        printf("\n 输入进程优先度:"); 
        scanf("%d",&p->super); 
        printf("\n 输入进程到达时间:"); 
        scanf("%d",&p->enterTime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        sort(p); /* 调用sort函数*/ 

        time = min(time, p->enterTime);
    } 
} 
int space() 
{ 
    return ps.size(); 
} 
void disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/ 
{ 
    printf("\n qname \t state \t super \t ndtime \t artime \t runtime \n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->super); 
    printf("|%d\t\t",pr->ntime); 
    printf("|%d\t\t",pr->enterTime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
}
void check() /* 建立进程查看函数 */ 
{ 
    if(p == NULL){
        printf("\n当前无运行进程");
    }else{
        printf("\n **** 当前正在运行的进程是:%s",p->name); /*显示当前运行进程*/ 
        disp(p); 
    }
    if(rp == NULL){
        printf("\n当前无准备进程");
    }else{
        printf("\n **** 当前的准备进程是:%s",rp->name); /*显示当前运行进程*/ 
        disp(rp); 
    }
    printf("\n ****当前后备队列状态为:\n"); /*显示就绪队列状态*/ 
    for (auto &&rp : psback)
    {
        disp(rp);
    }
} 
void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/ 
{ 
    printf("\n 进程 [%s] 已完成.\n",p->name); 
    free(p); 
    if(rp){
        p = rp;
        rp = NULL;
    }else{
        p = NULL;
    }
} 
void running() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/ 
{ 
    (p->rtime) += 10; 
    if(p->rtime % 100 >= 60) p->rtime = (p->rtime / 100 + 1) * 100 + p->rtime % 100 - 60;
    if(p->rtime==p->ntime) 
        destroy(); /* 调用destroy函数*/ 
    else 
    { 
        p->state='w'; 
    } 
} 
main() /*主函数*/ 
{ 
    system("chcp 65001");

    int len,h=-1;
    char ch; 
    input(); 
    len=space(); 
    while((len!=0)&&(!ps.empty() || p || rp || !psback.empty())) 
    { 
        ch=getchar(); 
        h++; 
        
        printf("\n The execute number:%d \n",h); 
        printf("\n CURTIME:%d \n",time); 
        int index = 0;

        while (index < ps.size())
        {
            if(ps[index]->enterTime > time){
                index++;
                continue;
            }
            if(p == NULL){
                p = ps[index];
            }else if (!rp)
            {
                rp = ps[index];
            }else{
                sort(ps[index], false);
            }
            
            ps.erase(ps.begin() + index);
        }
        
        if(!rp && !psback.empty()){
            rp = psback.front();
            psback.erase(psback.begin());
        }
        if(p && rp && p->super > rp->super) swap(p, rp);

        if(p){
            p->state='R'; 
            check(); 
            running(); 
        }else{
            p = NULL;
            check();
        }

        time += 10;
        if(time % 100 >= 60) time = (time / 100 + 1) * 100 + time % 100 - 60;
        
        printf("\n 按任一键继续......"); 
        ch=getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
    ch=getchar(); 
}

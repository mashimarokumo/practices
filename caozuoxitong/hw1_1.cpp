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
    int super; 
    int ntime; 
    int rtime; 
    int enterTime;
};
typedef struct pcb PCB; 
vector<PCB*> ps;
PCB *p;

void sort(pcb *cp) /* 建立对进程进行优先级排列函数*/ 
{ 
    ps.insert(upper_bound(ps.begin(), ps.end(), cp, [](PCB* a, PCB* b){ return a->super > b->super; }), cp);
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
        printf("\n 输入进程优先数:"); 
        scanf("%d",&p->super); 
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
void disp(PCB * pr) /*建立进程显示函数,用于显示当前进程*/ 
{ 
    printf("\n qname \t state \t super \t ndtime \t artime \t runtime \n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->super); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->enterTime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
}
void check() /* 建立进程查看函数 */ 
{ 
    if(p == NULL){
        printf("当前无运行进程");
    }else{
        printf("\n **** 当前正在运行的进程是:%s",p->name); /*显示当前运行进程*/ 
        disp(p); 
    }
    
    printf("\n ****当前就绪队列状态为:\n"); /*显示就绪队列状态*/ 
    for (auto &&rp : ps)
    {
        disp(rp);
    }
} 
void destroy() /*建立进程撤消函数(进程运行结束,撤消进程)*/ 
{ 
    printf("\n 进程 [%s] 已完成.\n",p->name); 
    free(p); 
} 
void running() /* 建立进程就绪函数(进程运行时间到,置就绪状态*/ 
{ 
    (p->rtime)++; 
    if(p->rtime==p->ntime) 
        destroy(); /* 调用destroy函数*/ 
    else 
    { 
        (p->super)--; 
        p->state='w'; 
        sort(p); /*调用sort函数*/ 
    } 
} 
main() /*主函数*/ 
{ 
    int len,h=-1; 
    char ch; 
    input(); 
    len=space(); 
    while((len!=0)&&(!ps.empty())) 
    { 
        ch=getchar(); 
        h++; 
        printf("\n The execute number:%d \n",h); 
        int index = 0;

        while (index < ps.size() && ps[index]->enterTime > h)
        {
            index ++;
        }
        if(index < ps.size()){
            p = ps[index];
            ps.erase(ps.begin() + index);
            p->state='R'; 
            check(); 
            running(); 
        }else{
            p = NULL;
            check();
        }
        
        printf("\n 按任一键继续......"); 
        ch=getchar(); 
    } 
    printf("\n\n 进程已经完成.\n"); 
    ch=getchar(); 
}

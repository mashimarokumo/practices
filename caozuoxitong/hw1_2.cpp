#include "stdio.h" 
#include <stdlib.h> 
#include <conio.h> 
#include <vector>
#include <algorithm>
using namespace std;
#define getpch(type) (type*)malloc(sizeof(type)) 

struct pcb { /* ������̿��ƿ�PCB */ 
    char name[10]; 
    char state; 
    int ntime; 
    int rtime; 
    int enterTime;
};
typedef struct pcb PCB; 
vector<PCB*> ps;
PCB *p;

void sort(pcb *cp) /* 建立对进程进行优先级排列函数*/ 
{ 
    ps.insert(upper_bound(ps.begin(), ps.end(), cp, [](PCB* a, PCB* b){ return a->enterTime < b->enterTime; }), cp);
} 
void input() /* �������̿��ƿ麯��*/ 
{ 
    int i,num; 
    system("cls"); /*����*/

    printf("\n ��������̺�?"); 
    scanf("%d",&num); 
    for(i=0;i<num;i++) 
    { 
        printf("\n ���̺�No.%d:\n",i); 
        pcb *p = getpch(pcb);
        printf("\n ���������:"); 
        scanf("%s",p->name); 
        printf("\n �����������ʱ��:"); 
        scanf("%d",&p->ntime); 
        printf("\n ������̵���ʱ��:"); 
        scanf("%d",&p->enterTime); 
        printf("\n"); 
        p->rtime=0;p->state='w'; 
        sort(p);
    } 
} 
int space() 
{ 
    return ps.size(); 
} 
void disp(PCB * pr) /*����������ʾ����,������ʾ��ǰ����*/ 
{ 
    printf("\n qname \t state \t ndtime \t artime \t runtime \n"); 
    printf("|%s\t",pr->name); 
    printf("|%c\t",pr->state); 
    printf("|%d\t",pr->ntime); 
    printf("|%d\t",pr->enterTime); 
    printf("|%d\t",pr->rtime); 
    printf("\n"); 
}
void check() /* �������̲鿴���� */ 
{ 
    if(p == NULL){
        printf("��ǰ�����н���");
    }else{
        printf("\n **** ��ǰ�������еĽ�����:%s",p->name); /*��ʾ��ǰ���н���*/ 
        disp(p); 
    }
    
    printf("\n ****��ǰ��������״̬Ϊ:\n"); /*��ʾ��������״̬*/ 
    for (auto &&rp : ps)
    {
        disp(rp);
    }
} 
void destroy() /*�������̳�������(�������н���,��������)*/ 
{ 
    printf("\n ���� [%s] �����.\n",p->name); 
    free(p); 
} 
void running() /* �������̾�������(��������ʱ�䵽,�þ���״̬*/ 
{ 
    (p->rtime)++; 
    if(p->rtime==p->ntime) 
        destroy(); /* ����destroy����*/ 
    else 
    { 
        p->state='w'; 
        ps.push_back(p);
    } 
} 
main() /*������*/ 
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
        
        printf("\n ����һ������......"); 
        ch=getchar(); 
    } 
    printf("\n\n �����Ѿ����.\n"); 
    ch=getchar(); 
}

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* next;        
};

struct Node* first;
struct Node* last;

void add(int val){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->val = val;
    if(first == NULL){
        first = node;
        last = node;
    }else{
        last->next = node;
        node->next = first;
        last = node;
    }
}

void del(int index){
    struct Node* p = first;
    int i = 0;

    while (i != index - 1)
    {
        i ++;
        p = p->next;
    }

    if(p->next == first){
        first = first->next;
    }
    if(p->next == last){
        last = p;
    } 
    struct Node* t = p->next;
    p->next = p->next->next;
    delete(t);
}

void delNext(struct Node* p){
    // struct Node* p = first;

    // while (p->next != node)
    // {
    //     p = p->next;
    // }

    if(p->next == first){
        first = first->next;
    }
    if(p->next == last){
        last = p;
    } 
    struct Node* t = p->next;
    p->next = p->next->next;
    //delete(t);
}

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        add(i);
    }

    struct Node* cur = first;

    while (first->next != first)
    {
        for (int i = 0; i < m - 2; i++)
        {
            cur = cur->next;
        }
        struct Node* tmp = cur->next->next;
        delNext(cur);

        cur = tmp;
    }
    
    printf("%d", first->val);
    return 0;
}

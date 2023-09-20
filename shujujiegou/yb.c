#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
	Node* next;
	int val;
} Node;
typedef struct circleList
{
	Node* head;
	int length;
} circleList;
void createNodes(circleList* nodes,int num)
{
	int index = 0;
	Node* node;
	node->val = index++;
	nodes->head = node;
	for (int i = 1; i < num; i++)
	{
		Node* _node;
		_node->val = i;
		node->next = _node;
		node = _node;
	}
	node->next = nodes->head;
	nodes->length = num;
}
Node* findFront(Node* node, circleList* nodes)
{
	Node* head = nodes->head;
	for (int i = 0; i < nodes->length ; i++)
	{
		if (head->next != node)
		{
			head = head->next;
		}
		else
		{
			return head;
		}
	}
	return NULL;
	
}
void del(Node* node,circleList* nodes)
{
	if (nodes->length <= 0)
	{
		free(node);
		nodes->length--;
	}
	if (node->next == NULL)
	{
		free(node);
		nodes->length--;
	}
	else
	{
		node = node->next;
		Node* front = findFront(node, nodes);
		if (front == NULL)
		{
			free(node);
			nodes->length--;
			return;
		}
		front->next = node->next;
		free(node);
		nodes->length--;
	}
}
void deleteByNum(Node* node, circleList* nodes,int interval)
{
	while (node->next != nodes->head)
	{
		for (int i = 0; i < interval; i++)
		{
			node = node->next;
		}
		del(node, nodes);
	}

}
int main()
{
	int n, m;
	scanf("%d%d",&n, &m);
	circleList* list;
	createNodes(list, n);
	deleteByNum(list->head,list, m);
	
}

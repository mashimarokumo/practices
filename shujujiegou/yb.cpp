#include<iostream>
using namespace std;


class Node
{
public:

	Node* next;
	int value;
	Node(int _value = NULL)
	{
		value = _value;
        next = NULL;
	}

};
class LinkList
{
public:
	Node* head;
	int len = 0;
	LinkList(Node* node)
	{
		head = node;
	}
};
void link(LinkList& list, Node* node)
{
	Node* tmp = list.head->next;
	list.head->next = node;
	node->next = tmp;
}

LinkList* nodeSort(LinkList l1, LinkList l2)
{
	Node* head = new Node();
	LinkList* ret = new LinkList(head);
	Node* retNode;
	retNode = head;
	int sum = l1.len + l2.len;

	Node* node1 = l1.head->next;
	Node* node2 = l2.head->next;
	for (int i = 0; i < sum; i++)
	{
		if (node1 == NULL)
		{
			link(*ret, node2);
			node2 = node2->next;
			continue;
		}
		else if (node2 == NULL)
		{
			link(*ret, node1);
			node1 = node1->next;
			continue;
		}
		else if (node2 == NULL && node1 == NULL)
		{
			break;
		}

		if (node1 && node2 && node1->value < node2->value)
		{
			Node* node = new Node(node1->value);
			link(*ret, node);
			node1 = node1->next;
		}
		else
		{
			Node* node = new Node(node2->value);
			link(*ret, node);
			node2 = node2->next;
		}
	}
	ret->len = sum + 1;
	return ret;
}

int main()
{
	int temp;
	Node* head1 = new Node();
	Node* head2 = new Node();

	LinkList llfst(head1);
	LinkList llsec(head2);
	Node* tmpNode = llfst.head;
	while (true)
	{
		cin >> temp;
		if (temp == -1)
		{
			break;
		}

		Node* node = new Node(temp);
		head1->next = node;
		head1 = head1->next;
		llfst.len++;
	}
	head1 = tmpNode;
	tmpNode = llsec.head;
	while (true)
	{
		cin >> temp;
		if (temp == -1)
		{
			break;
		}
		Node* node = new Node(temp);
		head2->next = node;
		head2 = head2->next;
		llsec.len++;
	}
	head2 = tmpNode;
	LinkList* ret;

	ret = nodeSort(llfst, llsec);
	Node* tmp = ret->head->next;


	for (int i = 0; i < ret->len - 1; i++)
	{

		cout << tmp->value << " ";
		tmp = tmp->next;
	}
}

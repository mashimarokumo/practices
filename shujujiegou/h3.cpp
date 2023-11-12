#include<iostream>

using namespace std;

class Node{
public:
    int val;
    Node* next = NULL;
    Node(int value){
        val = value;
    }
};

Node* input(){
    Node * root;
    int value;
    cin >> value;
    Node* node;
    if(value != -1) node = new Node(value);
    root = node;
    cin >> value;
    while(value != -1){
        Node* newnode = new Node(value);
        node = root;
        if(node->val >= newnode->val){
            newnode->next = root;
            root = newnode;
        }
        else{
            while (node->next != NULL && node->next->val < newnode->val)
            {
                node = node->next;
            }
            if(node->next == NULL){
                node->next = newnode;
            }else{
                newnode->next = node->next;
                node->next = newnode;
            }
        }
        cin >> value;
    }
    return root;
}

int main(){
    Node* root1 = input();
    Node* root2 = input();

    Node* lastNode = NULL;
    while (root1 != NULL && root2 != NULL)
    {
        if(root1->val < root2->val){
            Node * node = root1->next;
            root1->next = lastNode;
            lastNode = root1;
            root1 = node;
        }else{
            Node * node = root2->next;
            root2->next = lastNode;
            lastNode = root2;
            root2 = node;
        }
    }
    while (root1 != NULL)
    {
        Node * node = root1->next;
        root1->next = lastNode;
        lastNode = root1;
        root1 = node;
    }
    while (root2 != NULL)
    {
        Node * node = root2->next;
        root2->next = lastNode;
        lastNode = root2;
        root2 = node;
    }
    
    while (lastNode != NULL)
    {
        cout << lastNode->val << " ";
        lastNode = lastNode->next;
    }
    
    return 0;
}
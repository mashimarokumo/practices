#include<vector>
#include<map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    vector<Node*> list;
    map<Node*, int> nodeM;
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* pointer = head;
        Node* p2 = new Node(pointer->val);
        Node* newhead = p2;
        pointer = pointer->next; 
        nodeM[pointer] = list.size();


        while (pointer != NULL)
        {
            Node* node = new Node(pointer->val);

            p2->next = node;
            list.push_back(p2); 
            nodeM[pointer] = list.size();
            p2 = node;
            
            pointer = pointer->next;
        }
        list.push_back(p2); 

        pointer = head;
        p2 = newhead;
        while (pointer != NULL)
        {
            if(pointer->random){
                p2->random = list[nodeM[pointer->random]];
            }

            pointer = pointer->next;
            p2 = p2->next;
        }
        
        return newhead;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    Node a = Node(1);
    Node b = Node(2);
    a.next = &b;
    a.random = &b;
    b.random = &a;

    s.copyRandomList(&a);
    return 0;
}

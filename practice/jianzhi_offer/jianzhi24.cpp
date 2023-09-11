#include<vector>
#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = NULL;
        while (head != NULL)
        {
            ListNode* temp  = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
};

int main(){
    Solution s;
    ListNode node(1);
    ListNode node2(2);
    ListNode node3(3);
    node.next = &node2;
    node2.next = &node3;
    s.reverseList(&node);
}
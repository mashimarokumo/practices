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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *node = head;
        if(node->val == val) head = node->next;
        while (node->next!=NULL)
        {
            if(node->next->val == val){
                node->next = node->next->next;
                return head;
            }
            node = node->next;
        }
        return head;
    }
};
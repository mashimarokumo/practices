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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        if(l1 == NULL) return l2;
        else if (l2 == NULL)
        {
            return l1;
        }
        else if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        
        
        if(l1->val < l2->val){
            ans = l1;
            l1 = l1->next;
        }
        else{
            ans = l2;
            l2 = l2->next;
        }
        ListNode* head = ans;
        int p1 = 0,p2 = 0;
        while (l1 != NULL && l2 != NULL)
        {
            if(l1->val < l2->val){
                ans->next = l1;
                l1 = l1->next;
            }
            else{
                ans->next = l2;
                l2 = l2->next;
            }
            ans = ans->next;
        }
        
        while (l1 != NULL)
        {
            ans->next = l1;
            l1 = l1->next;
            ans = ans->next;
        }
        while (l2 != NULL)
        {
            ans->next = l2;
            l2 = l2->next;
            ans = ans->next;
        }
        
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    ListNode node(1);
    ListNode node2(2);
    ListNode node3(3);
    node.next = &node2;
    node2.next = &node3;
    ListNode node4(1);
    ListNode node5(2);
    ListNode node6(3);
    node4.next = &node5;
    node5.next = &node6;
    s.mergeTwoLists(&node, &node4);
    return 0;
}

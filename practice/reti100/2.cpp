#include<ListNode.h>

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1 : l2;
        if(!l1->next) swap(l1, l2);
        int jinwei = 0;
        ListNode* head = l1;
        while (l1->next)
        {
            if(l2) l1->val += l2->val + jinwei;
            else l1->val += jinwei;
            jinwei = 0;
            if(l1->val >= 10){
                jinwei = l1->val / 10;
                l1->val = l1->val % 10;
            }

            l1= l1->next;
            if(l2) l2 = l2->next;
            if(!l1->next && l2 && l2->next){
                l1->next = l2->next;
                l2->next = NULL;
            }
        }
        
        if(jinwei != 0 || l2){
            if(l2) l1->val += l2->val + jinwei;
            else l1->val += jinwei;
            jinwei = 0;
            if(l1->val >= 10){
                jinwei = l1->val / 10;
                l1->val = l1->val % 10;
            }
            if(jinwei != 0){
                ListNode* nNode = new ListNode(jinwei);
                l1->next = nNode;
            }
        }
        return head;
    }
};
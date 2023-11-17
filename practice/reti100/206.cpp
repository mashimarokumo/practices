#include<ListNode.h>

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = NULL;
        while (head)
        {
            ListNode* next = head->next;
            head->next = last;
            last = head;
            head = next;
        }
        
        return last;
    }
};
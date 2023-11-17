#include<ListNode.h>
#include<set>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*> nodes;
        while (headA || headB)
        {
            if(headA){
                if(nodes.count(headA)){
                    return headA;
                }else{
                    nodes.emplace(headA);
                }
                headA = headA->next;
            }

            if(headB){
                if(nodes.count(headB)){
                    return headB;
                }else{
                    nodes.emplace(headB);
                }
                headB = headB->next;
            }
        }
        
        return NULL;
    }
};
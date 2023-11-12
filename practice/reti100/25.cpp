#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) return head;
        ListNode* newHead = NULL;
        ListNode* slow = NULL;
        ListNode* fast = head;
        ListNode* last = NULL;
        while (head != NULL)
        {
            for (int i = 0; i < k; i++)
            {
                if(head == NULL){
                    last->next = fast;
                    return newHead;
                }
                head = head->next;
            }

            slow = reverse(fast, k);
            if(!newHead) newHead = slow;
            if(last){
                last->next = slow;
                last = fast;
            }else{
                last = fast;
            }
            fast = head;
        }
                
        return newHead;
    }

    //1->2->3->    3->2->1->
    //4->5->6->    6->5->4->
    ListNode* reverse(ListNode* node, int k){
        ListNode* last = NULL;
        for (int i = 0; i < k; i++)
        {
            ListNode* tmp = node->next;
            node->next = last;
            last = node;
            node = tmp;
        }

        return last;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    a->next = b;
    b->next = c;

    s.reverseKGroup(a, 2);
    return 0;
}

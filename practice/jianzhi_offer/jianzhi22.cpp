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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* newHead = head;
        for (int i = 0; i < k; i++)
        {
            head = head->next;
        }
        while (head != NULL)
        {
            head = head->next;
            newHead = newHead->next;
        }
        return newHead;
    }
};
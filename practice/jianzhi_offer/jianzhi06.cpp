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
    vector<int> reversePrint(ListNode* head) {
        vector<int> newlist;
        while (head != NULL)
        {
            newlist.insert(newlist.begin(), head->val);
            head = head->next;
        }
        
        return newlist;
    }
};

int main(){
    Solution s;
    ListNode node(1);
    ListNode node2(2);
    ListNode node3(3);
    node.next = &node2;
    node2.next = &node3;
    s.reversePrint(&node);
}
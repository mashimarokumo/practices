#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<ListNode*> dependency = vector<ListNode*>(numCourses);
        vector<bool> flag = vector<bool>(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            dependency[i] = (new ListNode(i));
        }

        for (int i = 0; i < prerequisites.size(); i++)
        {
            ListNode* node = dependency[prerequisites[i][0]]->next;
            while (node->next != NULL)
            {
                node = node->next;
            }
            
            node->next = dependency[prerequisites[i][1]];
        }
        
        for (int i = 0; i < dependency.size(); i++)
        {
            if(flag[i]) continue;
            ListNode* quick = dependency[i];
            ListNode* slow = dependency[i];

            while (quick != NULL && quick->next != NULL)
            {
                flag[slow->val] = true;
                quick = quick->next->next;
                slow = slow->next;
                if(quick == slow) return false;
            }
        }
        
        return true;
    }
};
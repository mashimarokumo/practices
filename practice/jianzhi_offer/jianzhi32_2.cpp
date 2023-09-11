#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode* > q;
        q.push(root);
        while (!q.empty())
        {
            int num = q.size();
            vector<int> oneLevel;
            for (int i = 0; i < num; i++)
            {
                oneLevel.push_back(q.front()->val);
                if(q.front()->left != NULL) q.push(q.front()->left);
                if(q.front()->right != NULL) q.push(q.front()->right);
                q.pop();
            }
            ans.push_back(oneLevel);
        }
        return ans;
    }
};
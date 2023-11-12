#include<TreeNode.h>
#include<queue>

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> oneFloor;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int num = 1;

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            oneFloor.push_back(node->val);
            num--;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            if(num == 0){
                num = q.size();
                ans.push_back(oneFloor);
                oneFloor = *(new vector<int>());
            }
        }
        
        return ans;
    }
};
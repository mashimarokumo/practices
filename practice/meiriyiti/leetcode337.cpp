#include "TreeNode.h"
#include <queue>

class Solution {
public:
    int rob(TreeNode* root) {
        queue<TreeNode*> q;
        int num;
        int val = 0;
        int index = 2;
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(root->val);
        if(root->left != NULL) q.push(root->left);
        if(root->right != NULL) q.push(root->right);
        num = q.size();

        while (!q.empty())
        {
            TreeNode* node = q.front();
            val += node->val;
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            num --;

            if(num == 0){
                num = q.size();
                dp.push_back(max(dp[index - 1], dp[index - 2] + val));
                val = 0;
                index ++;
            }
        }
        
        return dp[dp.size() - 1];
    }
};
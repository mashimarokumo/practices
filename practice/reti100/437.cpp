#include<TreeNode.h>

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum, vector<long long>());
    }

    int dfs(TreeNode* root, int targetSum, vector<long long> ways){
        if(root == NULL) return 0;
        int ans = 0;

        for (int i = 0; i < ways.size(); i++)
        {
            ways[i] += root->val;
            if (ways[i]==targetSum)
            {
                ans ++;
            }
        }
        ways.push_back(root->val);
        if(root->val == targetSum) ans ++;

        ans += dfs(root->left, targetSum, ways);
        ans += dfs(root->right, targetSum, ways);
        
        return ans;
    }
};
#include<TreeNode.h>

class Solution {
public:
    int n;
    int kthSmallest(TreeNode* root, int k) {
        return preOrder(root, k);
    }

    int preOrder(TreeNode* root,int k){
        if(root == NULL) return 0;
        
        int v = preOrder(root->left, k);
        if(v != 0) return v;
        if(++n == k){
            return root->val;
        }
        v = preOrder(root->right, k);
        if(v != 0) return v;
        return 0;
    }
};
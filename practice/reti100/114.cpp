#include<TreeNode.h>

class Solution {
public:
    void flatten(TreeNode* root) {
        preOrder(root);
    }

    TreeNode* preOrder(TreeNode* root){
        if(!root) return NULL;

        TreeNode* le = root->left;
        TreeNode* ri = root->right;
        if(le) root->right = le;
        root->left = NULL;

        TreeNode* l = preOrder(le);
        if(ri && l) l->right = ri;
        TreeNode* r = preOrder(ri);

        if(!l && !r) return root;
        else if(!r || !l) return r ? r : l;
        return r;
    }
};
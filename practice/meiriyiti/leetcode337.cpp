#include "TreeNode.h"
#include <queue>

class Solution {
public:
    int rob(TreeNode* root) {
        
    }

    void aforder(TreeNode* node){
        aforder(node->left);
        aforder(node->right);

        
    }
};
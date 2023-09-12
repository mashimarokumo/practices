#include<string>
#include<stack>
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;

        TreeNode* left = searchBST(root->left, val);
        TreeNode* right = searchBST(root->right, val);

        return left != NULL ? left : right;
    }
};
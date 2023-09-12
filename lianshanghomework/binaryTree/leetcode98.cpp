#include<vector>
#include<math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int last = -pow(2, 31);
    bool isfirst= true;
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        bool left = isValidBST(root->left);

        if(isfirst) isfirst = false;
        else if(last >= root->val) return false;
        last = root->val;

        bool right = isValidBST(root->right);
        return left && right;
    }
};
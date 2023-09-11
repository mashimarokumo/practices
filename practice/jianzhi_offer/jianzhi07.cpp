#include<vector>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return NULL;
        TreeNode * root = new TreeNode(preorder[0]);
        
        int i;
        for (i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == preorder[0]) break;
        }
        
        vector<int> leftpreorder((preorder.begin() + 1), (preorder.begin() + i + 1));
        vector<int> rightpreorder((preorder.begin() + 1 + i), (preorder.end()));
        vector<int> leftinorder((inorder.begin()), (inorder.begin() + i));
        vector<int> rightinorder((inorder.begin() + 1 + i), (inorder.end()));
        root->left = buildTree(leftpreorder, leftinorder);
        root->right = buildTree(rightpreorder, rightinorder);

        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> pre = {3,9,20,15,7};
    vector<int> in = {9,3,15,20,7};
    s.buildTree(pre, in);
    return 0;
}

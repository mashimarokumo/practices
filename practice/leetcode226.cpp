#include<string>
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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode * node = nodes.front();
            if(node != NULL){
                TreeNode * temp = node->left;
                node->left = node->right;
                node->right = temp;
                nodes.push(node->left);
                nodes.push(node->right);
            }
            nodes.pop();
        }
        
        return root;
    }
};
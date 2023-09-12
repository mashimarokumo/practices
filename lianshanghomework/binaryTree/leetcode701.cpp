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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }

        if(val > root->val){
            if(root->right == NULL){
                TreeNode* node = new TreeNode(val);
                root->right = node; 
            }
            else{
                insertIntoBST(root->right, val);
            }
        } 
        else if(val < root->val){
            if(root->left == NULL){
                TreeNode* node = new TreeNode(val);
                root->left = node; 
            }else{
                insertIntoBST(root->left, val);
            }
        }

        return root;
    }
};
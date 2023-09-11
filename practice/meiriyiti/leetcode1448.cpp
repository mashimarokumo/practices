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

    int goodNodes(TreeNode* root) {
        height(root, -10005);
        return ans;
    }

    void height(TreeNode* root, int max){
        if(root == NULL) return;
        if(root->val >= max){
            max = root->val;
            ans ++;
        }
        height(root->left, max);
        height(root->right, max);
    }
private:
    int ans;
};



#include<vector>
#include<queue>
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
    queue<TreeNode*> firstq;
    queue<TreeNode*> sq;
    int min = pow(2, 31) - 1;
    int getMinimumDifference(TreeNode* root) {
        if(root == NULL) return 0;
        firstq.push(root);
        while (!firstq.empty())
        {
            if(firstq.front()->left != NULL) sq.push(firstq.front()->left);
            if(firstq.front()->right != NULL) sq.push(firstq.front()->right);
            while (!sq.empty())
            {
                TreeNode* cmp = sq.front();
                sq.pop();
                if(abs(firstq.front()->val - cmp->val) < min){
                    min = abs(firstq.front()->val - cmp->val);
                }
                if(cmp->left != NULL) sq.push(cmp->left);
                if(cmp->right != NULL) sq.push(cmp->right);
            }
            if(firstq.front()->left != NULL) firstq.push(firstq.front()->left);
            if(firstq.front()->right != NULL) firstq.push(firstq.front()->right);
            firstq.pop();
        }
        return min;
    }
};
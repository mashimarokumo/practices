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
    void recoverTree(TreeNode* root) {
        midOrder(root);

        TreeNode* first;
        int index;
        for (int i = 0; i < mid.size() - 1; i++)
        {
            if(mid[i]->val > mid[i + 1]->val){
                first = mid[i];
                index = i;
                break;
            }
        }

        TreeNode* sec;
        for (int i = index + 1; i < mid.size(); i++)
        {
            if(mid[i]->val < first->val){
                sec = mid[i];
            }
        }
        int tmp = sec->val;
        sec->val = first->val;
        first->val = tmp;
    }

    vector<TreeNode*> mid;
    void midOrder(TreeNode* root){
        if(root == NULL) return;
        midOrder(root->left);
        
        mid.push_back(root);

        midOrder(root->right);
    }
};

//3 2 1 -> 1 2 3
//1 3 2 4 -> 1 2 3 4
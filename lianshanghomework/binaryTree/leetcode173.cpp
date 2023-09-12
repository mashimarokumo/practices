#include<vector>
#include<math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        midOrder(root);
    }
    
    int next() {
        if(++pointer < tree.size()){
            return tree[pointer]->val;
        }
        pointer--;
        return NULL;
    }
    
    bool hasNext() {
        return pointer + 1 < tree.size();
    }
private: 
    vector<TreeNode*> tree;
    int pointer = -1;
    void midOrder(TreeNode* root){
        if(root == NULL) return;
        midOrder(root->left);

        tree.push_back(root);

        midOrder(root->right);
    }
};

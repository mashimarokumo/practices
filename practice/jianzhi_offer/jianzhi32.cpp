#include<vector>
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
    vector<int> levelOrder(TreeNode* root) {
        vector<int> list;
        if(root == NULL) return list;
        queue<TreeNode*> nodeList;

        nodeList.push(root);
        while(!nodeList.empty()){
            list.push_back(nodeList.front()->val);
            if(nodeList.front()->left != NULL) nodeList.push(nodeList.front()->left);
            if(nodeList.front()->right != NULL) nodeList.push(nodeList.front()->right);
            
            nodeList.pop();
        }
        return list;
    }
};


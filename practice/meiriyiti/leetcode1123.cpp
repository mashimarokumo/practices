#include<string>
#include<math.h>
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
    vector<vector<int>> nodesWays;
    int ansVal;
    TreeNode* ans;

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, vector<int>());
        
        ansVal = nodesWays[0][nodesWays[0].size() - 1];
        if(nodesWays.size() > 1){
            for (int i = nodesWays[0].size() - 1; i >= 0; i--)
            {
                bool flag = true;
                ansVal = nodesWays[0][i];
                for (int j = 0; j < nodesWays.size(); j++)
                {
                    if(nodesWays[j][i] != ansVal) flag = false;
                }
                
                if(flag){
                    break;
                }
            }
        }
        preorder(root);
        return ans;

    }
    void preorder(TreeNode* root){
        if(root == NULL) return;
        if(root->val == ansVal) ans = root;
        
        preorder(root->left);
        preorder(root->right);
    }

    void depth(TreeNode* node, vector<int> way){
        if(node == NULL) return;
        way.push_back(node->val);
        
        if(node->left == NULL && node->right == NULL){
            if(nodesWays.size() == 0 || nodesWays[0].size() < way.size()){
                nodesWays.clear();
                nodesWays.push_back(way);
            }
            else if (nodesWays[0].size() == way.size())
            {
                nodesWays.push_back(way);
            }
            return;
        }

        depth(node->left, way);
        depth(node->right, way);

        return;
    }

};

int main(int argc, char const *argv[])
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    node1.left = &node2;
    node1.right = &node3;
    Solution s;
    s.lcaDeepestLeaves(&node1);
    return 0;
}

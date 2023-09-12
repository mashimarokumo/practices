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
    TreeNode* parent;
    TreeNode* keynode;
    TreeNode* prenode;
    TreeNode* lastNode;
    TreeNode* deleteNode(TreeNode* root, int key) {
        midOrder(root, key, NULL);
        int type;//0 root 1 left 2 right

        if(keynode == NULL) return root;

        if(parent == NULL) type = 0;
        else if(parent->left != NULL && parent->left->val == key){ 
            type = 1;
        }else{
            type = 2;
        }

        if(keynode->left != NULL && keynode->right != NULL){
            TreeNode* k = keynode;
            TreeNode* p = prenode;
            keynode = NULL;parent = NULL;prenode = NULL;
            midOrder(root, p->val, NULL);
            if(parent == NULL) type = 0;
            else if(parent->left != NULL && parent->left->val == p->val){ 
                type = 1;
            }else{
                type = 2;
            }
            k->val = p->val;
        }
        
        if(keynode->left == NULL && keynode->right == NULL){
            if(type == 1){
                parent->left = NULL;
            }
            else if(type == 2){
                parent->right = NULL;
            }else{
                root = NULL;
            }
        }else{
            if (type == 1)
            {
                parent->left = keynode->left != NULL ? keynode->left : keynode->right;
            }else if(type == 2){
                parent->right = keynode->left != NULL ? keynode->left : keynode->right;
            }else{
                root = keynode->left != NULL ? keynode->left : keynode->right;
            }
            
        }
        
        return root;
    }

    void midOrder(TreeNode* node, int key, TreeNode* p){
        if(node == NULL) return;
        midOrder(node->left,key, node);

        if(node->val == key){
            keynode = node;
            prenode = lastNode;
            parent = p;
        }

        lastNode = node;

        midOrder(node->right,key, node);
    }
};

int main(){
    TreeNode node2(2);
    TreeNode node1(1);
    TreeNode node3(3);
    
    node2.left = &node1;
    node2.right = &node3;
    Solution c;
    c.deleteNode(&node2, 2);
}
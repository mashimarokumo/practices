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


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stack<TreeNode*> s;
        string ans;

        while (!s.empty() || root != NULL)
        {
            while (root != NULL)
            {
                s.push(root);
                ans += to_string(s.top()->val) + ",";
                root = root->left;
            }

            TreeNode* temp = s.top();
            s.pop();
            root = temp->right;
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stack<TreeNode*> s;
        vector<int> nums;
        
        for (int i = 0; i < data.length(); i++)
        {
            int num = 0;
            while (data[i] != ',')
            {
                num = num * 10 + atoi(&data[i]);
                i++;
            }
            
            nums.push_back(num);
        }
        
        TreeNode root(nums[0]);
        s.push(&root);
        int p = 1;
        while (p < nums.size())
        {
             TreeNode node = TreeNode(nums[p]);
            if(nums[p] < s.top()->val){
                s.top()->left = &node;
                s.push(&node);
            }
            else
            {
                TreeNode * tmp;
                while(nums[p] > s.top()->val){
                    tmp = s.top();
                    s.pop();
                }
                tmp->right = &node;
                s.push(&node);
            }
            p++;
        }
        
        return &root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;

int main(){
    TreeNode node2(2);
    TreeNode node1(1);
    TreeNode node3(3);
    
    node2.left = &node1;
    node2.right = &node3;
    Codec c;
    c.deserialize(c.serialize(&node2));
}
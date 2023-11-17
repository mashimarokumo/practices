#include<iostream>

using namespace std;

template<typename T> class queue{    
public:
    queue(){
        st = 0;
        end = -1;
    }
    void push(T p){
        ps[++end] = p;
    }
    void pop(){
        st ++;
    }
    T top(){
        return ps[st];
    }
    int size(){
        return end - st + 1;
    }

    T ps[1005];
private:
    int end;
    int st;
};

class TreeNode{
public:
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    int val;
    TreeNode(int v){
        val = v;
    }
};
//  1
//2   4
// 3 5 6

//2 3 1 5 4 6
//3 2 5 6 4 1

TreeNode* Find(int in[], int post[], int inst, int inend, int postst, int postend){
    if(inst > inend) return NULL;
    else if(inst == inend) return new TreeNode(in[inst]);
    TreeNode* root = new TreeNode(post[postend]);

    int i;
    for (i = inst; i <= inend; i++)
    {
        if(in[i] == post[postend]) break;
    }
    
    root->left = Find(in, post, inst, i - 1, postst, postst + i - inst - 1);
    root->right = Find(in, post, i + 1, inend, postst + i - inst, postend - 1);

    return root;
}

int main(){
    int n;
    cin >> n;
    int inorder[n], postorder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> postorder[i];
    }

    TreeNode* root = Find(inorder, postorder, 0, n - 1, 0, n - 1);

    queue<TreeNode*> tr;

    if(root) tr.push(root);
    while (tr.size() > 0)
    {
        TreeNode* tn = tr.top();
        tr.pop();
        if(tn->left) tr.push(tn->left);
        if(tn->right) tr.push(tn->right);
        cout << tn->val << " ";
    }
    
    return 0;
}
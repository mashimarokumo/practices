#include<vector>
#include<map>

using namespace std;
// class TreeNode
//     {
//     public:
//         TreeNode(int _val){

//         }
//         int val;
//         TreeNode* parent;
//         TreeNode* left;
//         TreeNode* right;
// };

class LockingTree {
public:
    // map<TreeNode*, int> users;
    // map<int, TreeNode*> nodes;
    map<int, int> users;
    vector<int> parents;
    vector<vector<int>> child;
    LockingTree(vector<int>& parent) {
        parents = parent;
        child = vector<vector<int>>(parent.size(), vector<int>(2, -1));
        for (int i = 0; i < parent.size(); i++)
        {
            users[i] = -1;
            if(parent[i] == -1) continue;
            //nodes[i] = new TreeNode(i);
            if(child[parent[i]][0] == -1){
                child[parent[i]][0] = i;
            }else{
                child[parent[i]][1] = i;
            }
        }
    }
    
    bool lock(int num, int user) {
        if(users[num] == -1){
            users[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        if(users[num] == user){
            users[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        if(users[num] == -1 && (findlockedchild(child[num][0], false) || findlockedchild(child[num][1], false)) && (parents[num] == -1 || findunlockedparent(parents[num]))){
            users[num] = user;
            return true;
        }
        return false;
    }

    bool findlockedchild(int index, bool flag){
        if(index == -1) return flag;
        if(flag || users[index] != -1){
            flag = true;
            users[index] = -1;
        }
        return findlockedchild(child[index][0], flag) || findlockedchild(child[index][1], flag) ? true : false;
    }

    bool findunlockedparent(int index){
        if(users[index] == -1){
            return true;
        }
        if(parents[index] == -1) return false;
        return findunlockedparent(parents[index]) ? true : false;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> p = {-1, 0, 0, 1, 1, 2, 2};
    LockingTree lt = LockingTree(p);

    lt.lock(4, 1);
    lt.upgrade(0, 1);

    return 0;
}

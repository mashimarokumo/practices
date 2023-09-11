#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() && popped.empty()) return true;
        else if(pushed.empty() || popped.empty()) return false;
        int p = 1;
        check.push(pushed[0]);
        for (int i = 0; i < popped.size(); i++)
        {
            if(check.empty()){
                if(p >= pushed.size()) return false;
                check.push(pushed[p]);
                p++;
            }
            while (check.top() != popped[i] && p < pushed.size())
            {
                check.push(pushed[p]);
                p++;
            }
            if(check.top() == popped[i]){
                check.pop();
            }
        }
        return check.empty();
    }
private:
    stack<int> check;
};
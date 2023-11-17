#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        generate(n, stack<string>(), "");
        return ans;
    }

    void generate(int n, stack<string> cur, string curS){
        if(curS.size() > n*2 || cur.size() > n) return;
        else if (curS.size() == n*2 && cur.empty())
        {
            ans.push_back(curS);
            return;
        }
        
        if(cur.empty()){
            cur.push("(");
            generate(n, cur, curS + "(");
        }else{
            cur.push("(");
            generate(n, cur, curS + "(");
            cur.pop();
            cur.pop();
            generate(n, cur, curS + ")");
        }
    }
};
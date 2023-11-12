#include<string>

using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            string sqrts = to_string(i * i);
            if(dfs(sqrts, 0, i, 0)){
                ans += i * i;
            }
        }
        return ans;
    }

    bool dfs(string s, int pos, int target, int curSum){
        if(s.size() == pos && curSum == target) return true;

        int sum = 0;
        for (int i = pos; i < s.size(); i++)
        {
            sum = sum * 10 + s[i] - '0';

            if(sum + curSum > target) return false;
            if(dfs(s, i + 1, target, curSum + sum)){
                return true;
            }
        }
        
        return false;
    }
};
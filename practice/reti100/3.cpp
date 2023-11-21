#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int dp = 1;
        map<char, int> curS;
        int ans = 1, st = 0;

        curS.emplace(pair(s[0], 0));
        for (int i = 1; i < s.size(); i++)
        {
            if(curS.count(s[i]) && curS[s[i]] >= st){
                ans = max(ans, dp);
                dp -= curS[s[i]] - st;
                st = curS[s[i]] + 1;
            }else{
                dp += 1;
            }

            if(!curS.count(s[i])) curS.emplace(pair(s[i], i));
            else curS[s[i]] = i;
        }
        
        return max(ans, dp);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.lengthOfLongestSubstring("abcabcbb");
    return 0;
}

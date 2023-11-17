#include<string>
#include<vector>

using namespace std;

class Solution {
public:
//abcde               ade
//text2前n个中能匹配到第x个text1的子序列有dp[n][x]个
//dp[n][x] = max(dp[n-1][0~x]) + 是否相等
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.size() == 0 || text2.size() == 0) return 0;
        if(text1.size() > text2.size()){
            string tmp = text1;
            text1 = text2;
            text2 = tmp;
        }
        vector<vector<int>> dp = vector<vector<int>>(text2.size(), vector<int>(text1.size()));

        int j = 0;
        dp[0][0] = text2[0] == text1[0] ? 1 : 0;
        for (int i = 1; i < text1.size(); i++)
        {
            if(text2[j] == text1[i]) dp[0][i] = 1;
            dp[0][i] = max(dp[0][i], dp[0][i-1]);
        }

        while (++j < text2.size())
        {
            dp[j][0] = max(text2[j] == text1[0] ? 1 : 0, dp[j - 1][0]);
            for (int i = 1; i < text1.size(); i++)
            {
                if(text2[j] == text1[i]){
                    dp[j][i] = dp[j - 1][i - 1] + 1;
                }
                dp[j][i] = max(max(dp[j - 1][i], dp[j][i - 1]), dp[j][i]);
            }
            
        }
        
        return dp[text2.size() - 1][text1.size() - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.longestCommonSubsequence("abcba", "abcbcba");
    return 0;
}

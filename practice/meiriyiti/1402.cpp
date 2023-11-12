#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        sort(satisfaction.begin(), satisfaction.end());

        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1));
        //i道菜中选了j道
        //dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * sa[i-1])
        dp[0][0] = 0;

        for (int i = 1; i <= satisfaction.size(); i++)
        {
            for (int j = 1; j <= i; j++)
            {
                if(i == j) dp[i][j] = dp[i-1][j-1] + j * satisfaction[i-1];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] + j * satisfaction[i-1]);

                ans = max(ans, dp[i][j]);
            }
        }

        return ans;        
    }
};
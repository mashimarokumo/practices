//TLE
// class Solution {
// public:
//     int numRollsToTarget(int n, int k, int target) {
//         return dfs(n, k, target, 0);
//     }

//     int dfs(int n, int k, int target, int cursum){
//         if(n == 0) return cursum == target;
//         int ans = 0;
//         if(n * k + cursum < target) return 0;
//         for (int i = 1; i <= k; i++)
//         {
//             if(cursum + i > target) return ans;

//             ans += dfs(n - 1, k, target, cursum + i);
//         }
        
//         return ans;
//     }
// };
#include<vector>

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp = vector<vector<int>>(n + 1, vector<int>(k * n));

        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                for (int x = 1; x <= k; x++)
                {
                    if(j-x >= 0) dp[i][j] = (dp[i][j] + dp[i - 1][j - x]) % 1000000007;
                }
            }
        }
        
        return dp[n][target];
    }
};
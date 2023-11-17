#include<vector>

using namespace std;

class Solution {
public:
//dp[i][j] 以i结尾取j项能取到的最大和
//-2,1,-3,4,-1,2,1,-5,4
//dp[i][j] = max(dp[][j-1])
    int maxSubArray(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size());
        int ans = nums[0];

        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if(dp[i] > ans) ans = dp[i];
        }
        
        return ans;
    }
};
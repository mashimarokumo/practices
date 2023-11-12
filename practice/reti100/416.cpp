#include<vector>

using namespace std;
//TLE QAQ
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         bool res = false;
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i];
//         }
        
//         if(sum % 2 == 1) return false;

//         return calc(nums, 0, 0, sum / 2);
//     }

//     bool calc(vector<int> nums, int cur, int res, int target){
//         if(res == target) return true;
//         if(res > target) return false;
//         if(cur == nums.size()) return res == target;
//         bool out = false;

//         if(calc(nums, cur + 1, res + nums[cur], target) || calc(nums, cur + 1, res, target)) out = true;
        
//         return out;
//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if(nums.size() < 2) return false;

        int sum = 0, maxS = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            maxS = max(maxS, nums[i]);
        }
        
        if(sum % 2 == 1 || maxS > sum / 2) return false;

        //dp[i][j] 前i个元素中选取若干个能否满足结果等于j
        vector<vector<int>> dp = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1));

        dp[0][nums[0]] = true;
        if(nums[0] == sum / 2) return true;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < sum / 2 + 1; j++)
            {
                if(dp[i - 1][j]){
                    if(j + nums[i] == sum / 2) return true;
                    else if(j + nums[i] < sum / 2) dp[i][j + nums[i]] = true;
                    dp[i][j] = true;
                }
            }
        }
        
        return false;
    }
};
#include<vector>

using namespace std;
//TLE
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             count = max(longgerst(nums, i, -10005), count);
//         }
//         return count;
//     }

//     int longgerst(vector<int> nums, int st, int last){
//         if(st == nums.size()) return 0;
//         if(nums[st] > last){
//             return max(longgerst(nums, st + 1, last), longgerst(nums, st + 1, nums[st]) + 1);
//         }
//         return longgerst(nums, st + 1, last);
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp = vector<int>(nums.size(), 1);
        int count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            
            count = max(count, dp[i]);
        }
        return count;
    }
};
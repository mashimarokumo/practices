#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int k = i + 1; k < nums.size(); k++)
            {
                if(nums[i] + nums[k] == target){
                    ans = {i, k};
                    return ans;
                }
            }
            
        }

        return ans;
    }
};
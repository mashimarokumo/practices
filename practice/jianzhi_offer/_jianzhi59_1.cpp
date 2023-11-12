#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(nums.size() == 0) return ans;
        int l = 0, r = k - 1;

        while (r < nums.size())
        {
            ans.push_back(maxInV(vector<int>(nums.begin() + l++, nums.begin() + 1 + r++)));
        }
        return ans;
    }

    int maxInV(vector<int> nums){
        int _max = nums[0];
        for (auto &&i : nums)
        {
            _max = max(i, _max);
        }
        return _max;
    }
};


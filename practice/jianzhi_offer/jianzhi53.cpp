#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(target == nums[i]) count++;
            else if (target < nums[i])
            {
                return count;
            }
        }
        return count;
    }
};
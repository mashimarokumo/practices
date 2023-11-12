#include<vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int pos = 0;
        int times = 0;

        while (pos + nums[pos] < nums.size() - 1)
        {
            int p = pos;
            for (int i = pos + 1; i <= nums[pos] + pos; i++)
            {
                if(i + nums[i] > p + nums[p]) p = i;
            }
            
            if(pos != p) pos = p;
            else pos += nums[pos];
            times ++;
        }
        
        return times + 1;
    }
};
#include<vector>

using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        if(nums.size() == 0) return 0;
        int l = nums[0], r = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            l = min(l, nums[i]);
            r = max(r, nums[i]);
        }
        
        while (l < r)
        {
            int mid = (r + l) / 2;
            
            int res = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if(nums[i] <= mid){
                    res ++;
                    i++;
                }
            }

            if(res >= k){
                r = mid;
            }else{
                l = mid + 1;
            } 
        }

        return l;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> a = {2,3,5,9};
    s.minCapability(a, 2);
    return 0;
}

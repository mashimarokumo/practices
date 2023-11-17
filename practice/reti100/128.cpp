#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int st = 0, ans = 0, co = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i - 1]){
                co++;
            }
            else if(nums[i] != nums[i - 1] + 1){
                ans = max(i - st - co, ans);
                st = i;
                co = 0;
            }
        }
        
        return max((int)nums.size() - st - co, ans);
    }
};
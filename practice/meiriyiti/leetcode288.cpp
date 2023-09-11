#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        int start = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i - 1] + 1){
                if(start == nums[i - 1]){
                    ans.push_back(to_string(start));
                    start = nums[i];
                }
                else{
                    ans.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
                    start = nums[i];
                }
            }
        }

        if(start == nums[nums.size() - 1]){
                ans.push_back(to_string(start));
        }
        else{
            ans.push_back(to_string(start) + "->" + to_string(nums[nums.size() - 1]));
        }

        return ans;
    }
};
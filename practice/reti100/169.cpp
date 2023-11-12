#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> times;

        for (int i = 0; i < nums.size(); i++)
        {
            if(times.count(nums[i])){
                times[nums[i]] ++;
            }
            else{
                times[nums[i]] = 1;
            }

            if(times[nums[i]] > nums.size() / 2) return nums[i];
        }
        return 0;
    }
};
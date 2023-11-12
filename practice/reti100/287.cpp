#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> times;
        for (int i = 0; i < nums.size(); i++)
        {
            if(times[nums[i]] != 0) return nums[i];
            times[nums[i]] ++;
        }
        return -1;
    }
};
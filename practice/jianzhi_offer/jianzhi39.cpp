#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if(!pool.count(nums[i])){
                pool[nums[i]] = 1;
            }
            else{
                pool[nums[i]]++;
            }

            if(pool[nums[i]] > nums.size() / 2) return nums[i];
        }
        return 0;
    }
private:
    map<int, int> pool;
};
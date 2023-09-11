#include<vector>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            pool[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(pool[i] > 1) return pool[i];
        }
        
    }

private:
    int pool[100004] = {0};    
};
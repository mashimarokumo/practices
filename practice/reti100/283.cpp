#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum= 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0){
                zeroNum ++;
                nums.erase(nums.begin() + i);
                i --;
            }
        }
        
        for (int i = 0; i < zeroNum; i++)
        {
            nums.push_back(0);
        }
    }
};
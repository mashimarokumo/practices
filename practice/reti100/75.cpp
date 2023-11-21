#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = -1, two = nums.size();

        for (int i = 0; i < two; i++)
        {
            if(nums[i] == 0){
                zero ++;
                nums[zero] = 0;
            }else if (nums[i] == 2)
            {
                two -= 1;
                swap(nums[two], nums[i]);
                i --;
            }
            
            if(i > zero && i < two) nums[i] = 1;
        }
        
    }
};
#include<vector>

using namespace std;

class Solution {
public:
    vector<int>& nums;
    int tupleSameProduct(vector<int>& nums) {
        int a = 0, b = 1, c = nums.size() - 2, d = nums.size() - 1;
        int ans = 0;
        
        
    }

    int search(int b, int c){
        if(b >= c) return 0;
        int ans = 0;

        for (int i = 0; i < b; i++)
        {
            for (int j = nums.size() - 1; j >= 0; j--)
            {
                if(nums[i] * nums[j] == nums[c] * nums[b]) ans ++;
            }
        }
        
        
    }
};
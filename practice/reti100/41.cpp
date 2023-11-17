#include<vector>

using namespace std;

class Solution {
public:
//将数组作为哈希表
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0 && nums[i] < nums.size() && nums[i] != i + 1){
                if(nums[i] == nums[nums[i] - 1]) continue;
                int tmp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[tmp - 1] = tmp;
                i--;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        
        return nums.size() + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> a = {0,2,2,1,1};
    s.firstMissingPositive(a);
    return 0;
}

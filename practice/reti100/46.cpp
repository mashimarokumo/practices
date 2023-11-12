#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> v;
        if(nums.size() == 1){
            v.push_back(nums);
            return v;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int> n = nums;
            n.erase(n.begin() + i);
            vector<vector<int>> tmp = permute(n);
            for (int j = 0; j < tmp.size(); j++)
            {
                tmp[j].insert(tmp[j].begin(), nums[i]);
                v.push_back(tmp[j]);
            }
        }
        return v;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> nums = {1,2,3};
    s.permute(nums);
    return 0;
}

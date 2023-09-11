#include<vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int zeroCount = 0;
        int pre = 0;
        vector<int> ordered;
        while (nums[pre] == 0)
        {
            zeroCount ++;
            pre ++;
        }
        if(pre < nums.size()) ordered.push_back(nums[pre]);

        for (int i = pre + 1; i < nums.size(); i++)
        {
            if(nums[i] == 0) {
                zeroCount++;
                continue;
            }
            bool flag = false;
            for (int j = 0; j < ordered.size(); j++)
            {
                if(nums[i] < ordered[j]){
                    ordered.insert(ordered.begin() + j, nums[i]);
                    flag = true;
                    break;
                }
                else if(nums[i] == ordered[j]){
                    return false;
                }
            }
            if(!flag) ordered.push_back(nums[i]);
        }
        
        if(ordered.size() == 0 || ordered.size() == 1) return true;
        for (int i = 0; i < ordered.size() -1; i++)
        {
            if(ordered[i] + 1 != ordered[i + 1]){
                if(ordered[i] == ordered[i + 1]) return false;

                if(zeroCount == 0) return false;
                else{
                    zeroCount--;
                    ordered.insert(ordered.begin() + i + 1, ordered[i] + 1);
                }
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> a = {9,10,4,0,9};
    s.isStraight(a);
}
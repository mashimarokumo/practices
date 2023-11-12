//kantijie!!!!!!!!!!!!!!!!!!
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](int v1, int v2) -> bool{return v1 > v2;});
        return nums[k - 1];
    }
};
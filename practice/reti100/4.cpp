#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) swap(nums1, nums2);
        
        int tar = (nums1.size() + nums2.size()) - 1;
        for (int i = 0; i < nums2.size(); i++)
        {
            if(nums1.size() <= (tar + 1) / 2 || nums2[i] < nums1[(tar + 1) / 2]){
                nums1.insert(lower_bound(nums1.begin(), nums1.end(), nums2[i]), nums2[i]);
            }else{
                return (nums1[(tar + 1) / 2] + nums1[tar / 2]) / 2.0;
            }
        }
        
        return (nums1[(tar + 1) / 2] + nums1[tar / 2]) / 2.0;
    }
};
#include<vector>

using namespace std;

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> box1(10);
        int conum = 0;
        int min = nums1[0], min2 = nums2[0];
        for (int i = 0; i < nums1.size(); i++)
        {
            if(nums1[i] < min){
                min = nums1[i];
            }
            box1[nums1[i]] = true;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if(nums2[i] < min2){
                min2 = nums2[i];
            }
            if(box1[nums2[i]]){
                if(conum == 0 || nums2[i] < conum) conum = nums2[i];
            }
        }

        if(conum != 0) return conum;
        if (min < min2)
        {
            return min * 10 + min2;
        }
        return min2 * 10 + min;
    }
};
#include<vector>

using namespace std;

class Solution {
public:
    int giveGem(vector<int>& gem, vector<vector<int>>& operations) {
        if(gem.empty()) return 0;
        for (auto &&item : operations)
        {
            gem[item[1]] += gem[item[0]]/2;
            gem[item[0]] -= gem[item[0]]/2;
        }
        int max = gem[0], min = gem[0];
        for (auto &&item : gem)
        {
            if(item > max) max = item;
            if(item < min) min = item;
        }
        
        return max - min;
    }
};
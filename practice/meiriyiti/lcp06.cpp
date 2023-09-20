#include<vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int ans = 0;
        for (int i = 0; i < coins.size(); i++)
        {
            ans += minTimes(coins[i]);
        }
        
        return ans;
    }

    int minTimes(int coin){
        return coin % 2 == 0 ? coin / 2 : coin / 2 + 1;
    }
};
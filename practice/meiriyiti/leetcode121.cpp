#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minN = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            minN = min(minN, prices[i]);
            ans = max(ans, prices[i] - minN);
        }
        
        return ans;
    }
};
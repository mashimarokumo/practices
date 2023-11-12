#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int ans = 0, minP = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < minP){
                minP = prices[i];
            }else{
                if(prices[i] - minP > ans){
                    ans = prices[i] - minP;
                }
            }
        }
        
        return ans;
    }
};
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, bPrice = prices[0];
 
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i+1] < prices[i]){
                if(i != 0) ans += prices[i++] - bPrice;
                bPrice = prices[i++];
                while (i < prices.size() && prices[i] < bPrice)
                {
                    bPrice = prices[i++];
                }
                i--;
            }
        }
        
        ans += prices.back() - bPrice;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {7,1,5,3,6,4};

    Solution s;
    s.maxProfit(a);
    return 0;
}

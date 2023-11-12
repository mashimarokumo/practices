#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max1= 0 , max2 = 0, bPrice = prices[0];
 
        for (int i = 0; i < prices.size() - 1; i++)
        {
            if(prices[i+1] < prices[i]){
                if(i != 0){
                    if(max1 < prices[i] - bPrice){
                        max2 = max1;
                        max1 = prices[i++] - bPrice;
                    } 
                    else max2 = max(max2, prices[i++] - bPrice);
                }
                bPrice = prices[i++];
                while (i < prices.size() && prices[i] < bPrice)
                {
                    bPrice = prices[i++];
                }
                i--;
            }
        }
        
        if(max1 < prices.back() - bPrice){
            max2 = max1;
            max1 = prices.back() - bPrice;
        } 
        else max2 = max(max2, prices.back() - bPrice);
        return max1 + max2;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = {3,3,5,0,0,3,1,4};

    Solution s;
    s.maxProfit(a);
    return 0;
}

#include<vector>

using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> tenMulti;
    vector<int> constructArr(vector<int>& a) {
        ans = vector<int>(a.size());
        tenMulti = vector<int>((a.size()-1)/10 + 1);

        for (int i = 0; i < tenMulti.size(); i++)
        {
            tenMulti[i] = 1;
            for (int j = 0; j < 10; j++)
            {
                if(i*10+j >= a.size()) break;

                tenMulti[i] *= a[i*10+j];
            }
        }
        
        for (int i = 0; i < tenMulti.size(); i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if(i*10+j >= a.size()) break;
                ans[i*10+j] = 1;
                for (int k = 0; k < 10; k++)
                {
                    if(i*10+j >= a.size()) break;
                    if(j == k) continue;

                    ans[i*10+j] *= a[k];
                }
                for (int k = 0; k < tenMulti.size(); k++)
                {
                    if(i != k);
                    ans[i*10+j] *= tenMulti[k];
                }
                
                
            }
        }
        
        return ans;
    }
};
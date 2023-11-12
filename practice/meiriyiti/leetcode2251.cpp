#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> flowersLast;
        vector<int> flowersStart;
        vector<int> ans;
        
        for (int i = 0; i < flowers.size(); i++)
        {
            flowersStart.push_back(flowers[i][0]);
            flowersLast.push_back(flowers[i][1]);
        }
        
        sort(flowersLast.begin(), flowersLast.end());
        sort(flowersStart.begin(), flowersStart.end());

        int f = 0, l = 0;
        for (int i = 0; i < people.size(); i++)
        {
            // while (f < flowers.size() && p[i] >= flowers[f][0])
            // {
            //     f ++;
            // }
            f = upper_bound(flowersStart.begin(), flowersStart.end(), people[i]) - flowersStart.begin();
            // while (l < flowersLast.size() && p[i] > flowersLast[l][1])
            // {
            //     l ++;
            // }
            l = lower_bound(flowersLast.begin(), flowersLast.end(), people[i]) - flowersLast.begin();
            
            ans.push_back(f - l);
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> flowers = {{1,6},{3,7},{9,12},{4,13}};
    vector<int> p = {2,3,7,11};
    Solution s;
    s.fullBloomFlowers(flowers, p);
    return 0;
}

#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[0] < b[0] || a[0] == b[0] && a[1] < b[1];});

        int i = 0;
        while (i < intervals.size())
        {
            vector<int> inter;
            inter = intervals[i];
            while (i + 1 < intervals.size() && inter[1] >= intervals[i + 1][0])
            {
                inter[1] = max(intervals[i + 1][1], inter[1]);
                i++;
            }
            if(intervals[i] != inter) inter[1] = max(intervals[i][1], inter[1]);

            res.push_back(inter);
            i++;
        }
        
        return res;
    }
};
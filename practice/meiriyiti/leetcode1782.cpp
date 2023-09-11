#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> nodeECounts(n + 1);
        map<vector<int>, int> pairECounts;
        vector<int> cnts;

        for (int i = 0; i < edges.size(); i++)
        {
            for (int j = 0; j < 2; j++)
            {
                nodeECounts[edges[i][j]]++;
            }

            if(edges[i][0] > edges[i][1]){
                int temp = edges[i][0];
                edges[i][0] = edges[i][1];
                edges[i][1] = temp;
            }
            if(pairECounts.count(edges[i])){
                pairECounts[edges[i]]++;
            }
            else{
                pairECounts[edges[i]] = 1;
            }
        }
        
        vector<int> arr = nodeECounts;
        arr.erase(arr.begin(), arr.begin() + 1);
        sort(arr.begin(), arr.end());

        for (int i = 0; i < queries.size(); i++)
        {
            int ans = 0;
            
            for (int j = 0; j < n; j++)
            {
                //upper_bound(begin, end, target)返回begin到end-1中第一个大于target的数的地址（无则返回end）， 减去起始坐标地址得到对应下标
                //lower_bound 则为大于或等于
                //这里为求出第一个 边数(a)+边数(b)>queries[i] 的值，j即a点 故从b点开始寻找
                int k = upper_bound(arr.begin() + j + 1 ,arr.end(), queries[i] - arr[j]) - arr.begin();
                ans += n - k;
            }
            
            for(auto &[val, freq] : pairECounts){
                //刚刚多算了相邻边 这边排除掉不符合条件的
                if(nodeECounts[val[0]] + nodeECounts[val[1]] > queries[i] && nodeECounts[val[0]] + nodeECounts[val[1]] - freq <= queries[i])
                    ans --;
            }
            cnts.push_back(ans);
            
        }
        
        return cnts;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> a = {{1,2},{2,4},{1,3},{2,3},{2,1}};
    vector<int> b = {2, 3};
    s.countPairs(4, a, b);
    return 0;
}

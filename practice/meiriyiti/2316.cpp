#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> parents;
    vector<int> sizes;

    long long countPairs(int n, vector<vector<int>>& edges) {
        parents = vector<int>(n);
        sizes = vector<int>(n);
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
            sizes[i] = 1;
        }
        
        for (auto &&edge : edges)
        {
            Union(edge[0], edge[1]);
        }
        
        vector<bool> visited(n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int g = Find(i);
            if(!visited[g]){
                //3节点时 3 * 2 = 6
                ans += sizes[g] * (sizes[g] - 1);
                visited[g] = true;
            }
        }
        
        return (((long long)n * (long long)(n-1)) - ans) / 2;
    }

    int Find(int a){
        if(parents[a] == a)
        {
            return a;
        }
        return parents[a] = Find(parents[a]);
    }

    void Union(int a, int b){
        int ga = Find(a), gb = Find(b);
        if(ga == gb) return;

        if(sizes[ga] > sizes[gb]){
            parents[gb] = ga;
            sizes[ga] += sizes[gb];
        }else{
            parents[ga] = gb;
            sizes[gb] += sizes[ga];
        }
    }
};
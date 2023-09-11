#include<vector>

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        vector<bool> col(grid[0].size());
        int ans = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            bool flag = false;

            int val = 0;
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1){
                    if(col[j]) {
                        flag = true;
                        continue;
                    }
                    for (int k = i; k < grid.size(); k++)
                    {
                       if(grid[k][j] == 1) val++; 
                    }
                    col[j] = true;
                    
                }
            }
            if(val > 1 || flag) ans += val;
        }
        return ans;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> gird = {
    {0,0,1,0,1},
    {0,1,0,1,0},
    {0,1,1,1,0},
    {1,0,0,1,1},
    {0,0,1,1,0}};
    s.countServers(gird);
    return 0;
}

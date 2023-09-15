#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<bool>> grid = vector<vector<bool>>(8, vector<bool>(8, false));
    vector<vector<int>> ans;
    
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {

        for (int i = 0; i < queens.size(); i++)
        {
            grid[queens[i][0]][queens[i][1]] = true;
        }
        
        ans.push_back(findQ(king, 1, 1));
        ans.push_back(findQ(king, -1, 1));
        ans.push_back(findQ(king, -1, -1));
        ans.push_back(findQ(king, 1, -1));
        ans.push_back(findQ(king, 0, 1));
        ans.push_back(findQ(king, 0, -1));
        ans.push_back(findQ(king, -1, 0));
        ans.push_back(findQ(king, 1, 0));

        for (int i = 0; i < ans.size(); i++)
        {
            if(ans[i][0] == -1){
                ans.erase(ans.begin() + i, ans.begin() + i+1);
                i--;
            }
        }
        
        return ans;
    }

    vector<int> findQ(vector<int> kingPos, int delx, int dely){
        kingPos[0] += delx;
        kingPos[1] += dely;
        while (kingPos[0]>=0&&kingPos[1]>=0&&kingPos[0]<8&&kingPos[1]<8)
        {
            if(grid[kingPos[0]][kingPos[1]]){
                return {kingPos[0], kingPos[1]};
            }
            kingPos[0] += delx;
            kingPos[1] += dely;
        }
        return {-1, -1};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> q = {{0,0},{1,1},{2,2},{3,4},{3,5},{4,4},{4,5}};
    vector<int> k ={3,3};
    s.queensAttacktheKing(q, k);
    return 0;
}

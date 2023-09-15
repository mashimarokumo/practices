#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>> index = vector<vector<int>>(grid.size() * grid[0].size());
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                index[grid[i][j]] = {i,j};
            }
        }
        if(index[0][0] != 0 || index[0][1] != 0) return false;

        for (int i = 0; i < index.size() - 1; i++)
        {
            if(!isNextValid(index[i], index[i + 1])) return false;
        }
        

        return true;
    }

    bool isNextValid(vector<int> first, vector<int> next){
        return abs(first[0] - next[0]) == 1 && abs(first[1] - next[1]) == 2 || abs(first[0] - next[0]) == 2 && abs(first[1] - next[1]) == 1 ;
    }
};

//[24,11,22,17,4],
//[21,16, 5,12,9],
//[6,23,10, 3,18],
//[15,20,1, 8,13],
//[0, 7,14,19, 2]
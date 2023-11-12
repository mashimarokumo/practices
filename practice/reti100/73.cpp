#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> row = vector<bool>(matrix.size());
        vector<bool> col = vector<bool>(matrix[0].size());

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        for (int i = 0; i < row.size(); i++)
        {
            if(row[i]){
                for (int j = 0; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int i = 0; i < col.size(); i++)
        {
            if(col[i]){
                for (int j = 0; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    }
};
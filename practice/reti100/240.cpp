#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int l = 0, r = matrix[0].size() - 1;

        while (l < matrix.size() && r >= 0)
        {
            if(matrix[l][r] == target) return true;
            else if (matrix[l][r] > target)
            {
                r --;
            }else{
                l ++;
            }
        }
        
        return false;
    }
};

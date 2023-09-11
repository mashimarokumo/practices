#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> list;
        if(matrix.size() == 0) return list;
        int up = 0, down = matrix.size()-1, left = 0, right = matrix[0].size()-1;
        while (up <= down || left <= right)
        {
            if(up<= down){
                for (int i = left; i <= right; i++)
                {
                    list.push_back(matrix[up][i]);
                }
                up++;
            }
            if(left <= right){
                for (int i = up; i <= down; i++)
                {
                    list.push_back(matrix[i][right]);
                }
                right--;
            }
            if(up <= down){
                for (int i = right; i >= left; i--)
                {
                    list.push_back(matrix[down][i]);
                }
                down--;
            }
            if(left <= right){
                for (int i = down; i >= up; i--)
                {
                    list.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        
        return list;
    }
};

int main(){
    vector<vector<int>> matrix;
    Solution s;
    s.spiralOrder(matrix);
}
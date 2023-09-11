#include<string>
#include<vector>
#include<iostream>

#include<math.h>

using namespace std;

class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        _pizza = pizza;
        for (int i = 0; i < pizza.size(); i++)
        {
            for (int j = 0; j < pizza[0].length(); j++)
            {
                for (int l = 1; l <= k; l++)
                {
                    apple[i][j][l] = -1;
                }
                
            }
            
        }
        
        return Cut(0, 0, k)  % (int)(pow(10, 9) + 7);
    }

private:
    vector<string> _pizza;
    int apple[50][50][10];

    long Cut(int col, int row, int k){
        if(apple[row][col][k] != -1) return apple[row][col][k];
        
        long ans = 0;
        if((k != 1 && CutableNum(col, row) < k-1) || !hasApple(col, row)) return 0;

        if(k == 1){
            return 1;
        }

        for(int i = row+1; i < _pizza.size(); i++){
            //if(i == 1) lostPizza.insert(lostPizza.begin(), pizzaleft[0]);
            if(hasApple(col, row, _pizza[0].length(), i)){
                ans += Cut(col, i, k-1);
            }
        }

        for (int i = col+1; i < _pizza[0].size(); i++)
        {
             if(hasApple(col, row, i, _pizza.size())){
                ans += Cut(i, row, k-1);
            }
        }
        
        apple[row][col][k] = ans;
        return ans;
    }

    int CutableNum(int col, int row){
        return _pizza.size() - col + _pizza[0].length() - row - 2;
    }

    bool hasApple(int col, int row){
        return hasApple(col, row, _pizza[0].length(), _pizza.size());
    }

    bool hasApple(int col, int row, int ecol, int erow){
        for(int i = row; i < erow; i++){
            for (int j = col; j < ecol; j++)
            {
                if(_pizza[i][j] == 'A'){
                    return true;
                }
            }
            
        }
        return false;
    }
};

int main(){
    Solution s;
    vector<string> pizza = {"..A.A.AAA...AAAAAA.AA..A..A.A......A.AAA.AAAAAA.AA","A.AA.A.....AA..AA.AA.A....AAA.A........AAAAA.A.AA.","A..AA.AAA..AAAAAAAA..AA...A..A...A..AAA...AAAA..AA","....A.A.AA.AA.AA...A.AA.AAA...A....AA.......A..AA.","AAA....AA.A.A.AAA...A..A....A..AAAA...A.A.A.AAAA..","....AA..A.AA..A.A...A.A..AAAA..AAAA.A.AA..AAA...AA","A..A.AA.AA.A.A.AA..A.A..A.A.AAA....AAAAA.A.AA..A.A",".AA.A...AAAAA.A..A....A...A.AAAA.AA..A.AA.AAAA.AA.","A.AA.AAAA.....AA..AAA..AAAAAAA...AA.A..A.AAAAA.A..","A.A...A.A...A..A...A.AAAA.A..A....A..AA.AAA.AA.AA.",".A.A.A....AAA..AAA...A.AA..AAAAAAA.....AA....A....","..AAAAAA..A..A...AA.A..A.AA......A.AA....A.A.AAAA.","...A.AA.AAA.AA....A..AAAA...A..AAA.AAAA.A.....AA.A","A.AAAAA..A...AAAAAAAA.AAA.....A.AAA.AA.A..A.A.A...","A.A.AA...A.A.AA...A.AA.AA....AA...AA.A..A.AA....AA","AA.A..A.AA..AAAAA...A..AAAAA.AA..AA.AA.A..AAAAA..A","...AA....AAAA.A...AA....AAAAA.A.AAAA.A.AA..AA..AAA","..AAAA..AA..A.AA.A.A.AA...A...AAAAAAA..A.AAA..AA.A","AA....AA....AA.A......AAA...A...A.AA.A.AA.A.A.AA.A","A.AAAA..AA..A..AAA.AAA.A....AAA.....A..A.AA.A.A...","..AA...AAAAA.A.A......AA...A..AAA.AA..A.A.A.AA..A.",".......AA..AA.AAA.A....A...A.AA..A.A..AAAAAAA.AA.A",".A.AAA.AA..A.A.A.A.A.AA...AAAA.A.A.AA..A...A.AAA..","A..AAAAA.A..A..A.A..AA..A...AAA.AA.A.A.AAA..A.AA..","A.AAA.A.AAAAA....AA..A.AAA.A..AA...AA..A.A.A.AA.AA",".A..AAAA.A.A.A.A.......AAAA.AA...AA..AAA..A...A.AA","A.A.A.A..A...AA..A.AAA..AAAAA.AA.A.A.A..AA.A.A....","A..A..A.A.AA.A....A...A......A.AA.AAA..A.AA...AA..",".....A..A...A.A...A..A.AA.A...AA..AAA...AA..A.AAA.","A...AA..A..AA.A.A.AAA..AA..AAA...AAA..AAA.AAAAA...","AA...AAA.AAA...AAAA..A...A..A...AA...A..AA.A...A..","A.AA..AAAA.AA.AAA.A.AA.A..AAAAA.A...A.A...A.AA....","A.......AA....AA..AAA.AAAAAAA.A.AA..A.A.AA....AA..",".A.A...AA..AA...AA.AAAA.....A..A..A.AA.A.AA...A.AA","..AA.AA.AA..A...AA.AA.AAAAAA.....A.AA..AA......A..","AAA..AA...A....A....AA.AA.AA.A.A.A..AA.AA..AAA.AAA","..AAA.AAA.A.AA.....AAA.A.AA.AAAAA..AA..AA.........",".AA..A......A.A.AAA.AAAA...A.AAAA...AAA.AAAA.....A","AAAAAAA.AA..A....AAAA.A..AA.A....AA.A...A.A....A..",".A.A.AA..A.AA.....A.A...A.A..A...AAA..A..AA..A.AAA","AAAA....A...A.AA..AAA..A.AAA..AA.........AA.AAA.A.","......AAAA..A.AAA.A..AAA...AAAAA...A.AA..A.A.AA.A.","AA......A.AAAAAAAA..A.AAA...A.A....A.AAA.AA.A.AAA.",".A.A....A.AAA..A..AA........A.AAAA.AAA.AA....A..AA",".AA.A...AA.AAA.A....A.A...A........A.AAA......A...","..AAA....A.A...A.AA..AAA.AAAAA....AAAAA..AA.AAAA..","..A.AAA.AA..A.AA.A...A.AA....AAA.A.....AAA...A...A",".AA.AA...A....A.AA.A..A..AAA.A.A.AA.......A.A...A.","...A...A.AA.A..AAAAA...AA..A.A..AAA.AA...AA...A.A.","..AAA..A.A..A..A..AA..AA...A..AA.AAAAA.A....A..A.A"};
    //vector<string> pizza = {"A..","AAA","..."};
    cout << s.ways(pizza, 8);
}
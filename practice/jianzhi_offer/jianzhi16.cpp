#include<iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || x == 0) return x;
        if(x==-1){
            if(n % 2 == 0) return 1;
            return -1;
        }

        double ans = 1;
        if(n > 0){
            if(x < 1 && x > -1 && n > 10000000) return 0; 
            for (int i = 0; i < n; i++)
            {
                ans *= x;
            }
        }
        else if (n < 0)
        {
            if(n < -10000000) return 0;
            for (long i = 0; i > n; i--)
            {
                ans *= x;
            }
            ans = 1 / ans;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.myPow(2, -2147483648);
}
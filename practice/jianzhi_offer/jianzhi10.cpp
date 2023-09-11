#include<math.h>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(fibs[n] == 0) fibs[n] = fib(n - 1) + fib(n - 2);
        return fibs[n] % (int)(pow(10, 9) + 7);
    }
private:
    long fibs[101] = {0};
};

int main(){
    Solution s;
    int x = s.fib(100);
}
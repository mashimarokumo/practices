#include<math.h>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if(n == 0) return 1;
        if(n == 1 || n == 2) return n;

        if(pool[n] == 0) pool[n] = numWays(n-1) + numWays(n - 2);
        return pool[n] % (int)(pow(10, 9) + 7);
    }
private:
    int pool[101] = {0};
};
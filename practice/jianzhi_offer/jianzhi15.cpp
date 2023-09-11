#include<stdint-gcc.h>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n != 0){
            if(n % 2 != 0){
                ans ++;
            }
            n = n/2;
        }
        return ans;
    }
};

int main(){
    Solution s;
    s.hammingWeight(00000000000000000000000000001011);
}
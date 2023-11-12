#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int l = 0, r = 2;
        if(flowerbed.size() == 1) return n == 0 || n == 1 && flowerbed[0] == 0;
        
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            n --;
            l = 1;
            r = l + 2;
        }

        while (r < flowerbed.size())
        {
            for (int i = l; i <= r; i++)
            {
                if(r >= flowerbed.size()){
                    return flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0 ? n - 1 <= 0 : n <= 0;
                }
                if(flowerbed[i] == 1){
                    l = i + 1;
                    r = l + 2;
                }
            }

            n --;
            l = r;
            r = l + 2;
        }
        
        if(r < flowerbed.size() + 1){
            return flowerbed[flowerbed.size() - 2] == 0 && flowerbed[flowerbed.size() - 1] == 0 ? n - 1 <= 0 : n <= 0;
        }
        return n <= 0;
    }
};
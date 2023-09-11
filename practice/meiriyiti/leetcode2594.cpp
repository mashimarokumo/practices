#include <vector>
#include<algorithm>
#include<math.h>

using namespace std;

class Solution {
public:
    //vector<int> box = vector<int>(101);
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        vector<int> carNums(ranks.size());
        int maxTimeIndex = ranks.size() - 1;
        //int left = cars;

        while(cars > 0){
            for (int i = ranks.size() - 1; i >= 0; i--)
            {
                if(i == ranks.size() - 1){
                    carNums[i]++;
                    cars--;
                    //box[ranks[i]] = carNums[i];
                }

                // if(box[ranks[i]] != 0 && carNums[i] != box[ranks[i]]){
                //     int car = box[ranks[i]] -carNums[i];
                //     carNums[i] += cars > car ? car : cars;
                //     cars = cars > car ? (cars - car) : 0;
                //     continue;
                // }

                while(pow(carNums[i] + 1, 2) * ranks[i] <= pow(carNums[maxTimeIndex], 2) * ranks[maxTimeIndex] && cars > 0){
                    carNums[i]++;
                    cars--;
                    //box[ranks[i]] = carNums[i];
                }
            }
            
        }

        for (int i = 0; i < ranks.size(); i++)
        {
            while (pow(carNums[maxTimeIndex], 2) * ranks[maxTimeIndex] > pow(carNums[i] + 1, 2) * ranks[i])
            {
                carNums[i] ++;
                carNums[maxTimeIndex] --;
                for (int j = 0; j < ranks.size(); j++)
                {
                    if(ranks[j] <= ranks[maxTimeIndex] && carNums[j] <= carNums[maxTimeIndex]) continue;
                    if(ranks[j] > ranks[maxTimeIndex] && carNums[j] > carNums[maxTimeIndex]) maxTimeIndex = j;
                    else if(pow(carNums[maxTimeIndex], 2) * ranks[maxTimeIndex] < pow(carNums[j], 2) * ranks[j]) maxTimeIndex = j;
                }
                
            }
        }
        
        return pow(carNums[maxTimeIndex], 2) * ranks[maxTimeIndex];
        
    }

};

int main(int argc, char const *argv[])
{
    Solution s;
    s.repairCars(*(new vector<int>{5,1,8}), 6);
    return 0;
}

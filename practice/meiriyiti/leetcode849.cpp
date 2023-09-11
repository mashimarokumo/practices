#include<vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int max = 0;
        bool flag = false;
        int lastSeat = -1;

        for (int i = 0; i < seats.size(); i++)
        {
            if(seats[i] == 1){
                if(i - lastSeat == 1) {lastSeat = i; continue;}
                if (flag)
                {
                    max = i;
                    flag = false;
                }
                else{
                    max = (i - lastSeat) / 2 > max ? (i - lastSeat) / 2 : max;
                }
                lastSeat = i;
            }
            else if (i == 0)
            {
                flag = true;
            }
            else if (i == seats.size() - 1)
            {
                max = i - lastSeat > max ? i - lastSeat : max;
            }
            
        }

        return max;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> a ={0,0,1};
    s.maxDistToClosest(a);
    return 0;
}

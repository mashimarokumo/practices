#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sorted(courses);

        int time = 0;
        queue<int> q;

        for (int i = 0; i < courses.size(); i++)
        {
            if(time + courses[i][0] < courses[i][1]){
                q.push(courses[i][0]);
            }
            else if(!q.empty() && q.front() > courses[i][0])
            {
                time += courses[i][0];
                time -= q.front();

                q.push(courses[i][0]);
                q.pop();
            }
            
        }
        
    }

    void sorted(vector<vector<int>>& tosort){
        for (int i = 0; i < tosort.size(); i++)
        {
            int k = i;
            for (int j = i + 1; j < tosort.size(); j++)
            {
                if(tosort[k][1] > tosort[j][1] || (tosort[k][1] == tosort[j][1] && tosort[k][0] > tosort[j][0])){
                    k = j;
                }
            }
            if(k != i){
                vector<int>* tmp = new vector<int>(tosort[k]);
                tosort[k] = tosort[i];
                tosort[i] = *tmp;
            }
        }
    }

    // int dfs(int num, int time, vector<vector<int>>& _courses){
    //     int max = 0;
    //     for (int i = num + 1; i < _courses.size(); i++)
    //     {
    //         if(_courses[i][0] + time <= _courses[i][1]){
    //             int res = dfs(i, _courses[i][0] + time, _courses) + 1;
    //             if(res > max){
    //                 max = res;
    //             }
    //         }
    //     }
    //     return max;
    // }
};

//5/1 6 5 11 2 12 3 13 8 15 8 18
//   0   1    5    5    2    5
//

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> a = {{3,14},{6,18},{10,16},{3,4},{4,5},{7,15},{2,9},{1,6},{10,13},{5,16}};
    s.scheduleCourse(a);
    return 0;
}

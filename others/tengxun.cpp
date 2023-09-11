// 本题为考试单行多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
int main() {
    vector<pair<int, int>> places;
    for (int i = 0; i < 4; i++)
    {
        int a,b;
        cin >> a >> b;
        places.push_back(pair(a, b));
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if(places[i].first == places[j].first){
                
            }
        }
        
    }
    
    
}
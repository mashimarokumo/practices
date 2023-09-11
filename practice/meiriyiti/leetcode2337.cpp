#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int p = 0;
        for (int i = 0; i < start.length(); i++)
        {
            if(start[i] == 'L' || start[i] == 'R'){
                while (p < target.length() && target[p] != 'L' && target[p] != 'R')
                {
                    p++;
                }
                if(start[i] != target[p]) return false;
                else if(start[i] == 'L' && i < p) return false;
                else if (start[i] == 'R' && i > p) return false;
                p++;
            }
        }

        while (p < target.length())
        {
            if(target[p] == 'L' || target[p] == 'R'){
                return false;
            }
            p++;
        }
        
        return true;
    }
};

int main(){
    Solution s;
    cout << s.canChange("_L__R__R_", "L______RR");
}
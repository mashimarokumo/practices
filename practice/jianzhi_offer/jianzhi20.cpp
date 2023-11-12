#include<string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int p = 0, f = 0;
        
        while (p < s.size())
        {
            if(p == '.'){
                int valid = hasValidNum(string(s.begin() + f, s.begin() + f + p));
                if(valid == -1){
                    return false;
                }else if (valid == 0)
                {
                    p++;
                    f = p;
                }else{
                    p++;
                    f = p;
                }
                
            }else if(p == 'e' || p == 'E'){

            }
        }
        
    }

    //-1 invalid 0 none 1 have
    int hasValidNum(string s){
        int p = 0;
        while (p < s.size() && s[p] == ' ')
        {
            p++;
        }
        
        if(s[p] == '+' || s[p] == '-'){
            p++;
        }

        if(p == s.size()) return 0;
        while (p < s.size())
        {
            if(s[p] >= '0' || s[p] <= '9'){
                p++;
            }else{
                return -1;
            }
        }
        return p == s.size();
    }
};
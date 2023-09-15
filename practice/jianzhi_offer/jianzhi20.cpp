#include<string>

using namespace std;

class Solution {
public:
    int p = 0;
    bool isNumber(string s) {
        
        while (s[p] == ' ')
        {
            p++;
        }

        if(getInt(s))
        
        
    }

    bool getInt(string s){
        int i = p;
        if(s[p] == '+' || s[p] == '-'){
            p++;
            i = p;
        }
        while (p < s.size() && isNum(s[p]))
        {
            p++;
        }
        if(i == p){
            p = s[p] == '+' || s[p] == '-' ? i-1 : i;
            return false;
        }
        return true;
    }

    bool getFl(string s){
        int i = p; bool hasNum;
        if(s[p] == '+' || s[p] == '-'){
            p++;
            i == p;
        }
        while (p < s.size() && isNum(s[p]))
        {
            p++;
            hasNum = true;
        }
        if(p < s.size() && p[s] == )
    }

    bool isNum(char c){
        return c >= '0' && c <= '9';
    }
};
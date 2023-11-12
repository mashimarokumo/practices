#include<string>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0,st = 0, e = 0, len = 0, ans = 0;
        for (int i = 0; i < s.size(); i ++)
        {
            if(s[i] == '('){
                if(left == 0) st = i;
                left ++;
            }else if(left <= 0){
                st = i + 1;
            }else{
                left --;

                if(left == 0){
                    if(st == e + 1){
                        len += i - st + 1;
                    }else{
                        len = i - st + 1;
                    }

                    e = i;
                    ans = max(len, ans);
                }
            }
        }

        if(left > 0) len = s.size() - st - left;
        
        return max(ans, len);
    }
};
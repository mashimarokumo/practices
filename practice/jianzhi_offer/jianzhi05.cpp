#include<string>
#include<iostream>

#include<math.h>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        for (int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' '){
                s.erase(i, 1);
                s.insert(i, "%20");
                i += 2;
            }
        }
        return s;
    }
};

int main(){
    Solution s;
    cout << s.replaceSpace("h jo");
}
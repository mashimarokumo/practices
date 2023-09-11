#include<string>
# include<iostream>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string a;
        a.assign(s.begin(), s.begin() + n);
        s.erase(0, n);
        return s + a;
    }
};

int main(){
    Solution s;
    cout << s.reverseLeftWords("hello", 1);
}
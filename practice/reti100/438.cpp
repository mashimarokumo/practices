#include<vector>
#include<string>
#include<map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = p.size();

        map<char, int> ps;
        queue<pair<char, int>> ins;
        for (int i = 0; i < n; i++)
        {
            if(ps.count(p[i])) ps[p[i]] ++;
            else ps.emplace(pair<char, int>(p[i], 1));
        }

        for (int i = 0; i < s.size(); i++)
        {
            ins.push(pair<char, int>(s[i], i));
            if(ps.count(s[i])){
                if(ps[s[i]] > 0) n --;
                ps[s[i]] --;
            }

            if(n == 0){
                ans.push_back(ins.front().second);
            }

            if(ins.size() >= p.size()){
                if(ps.count(ins.front().first)){
                    ps[ins.front().first] ++;
                    if(ps[ins.front().first] > 0) n ++;
                }
                
                ins.pop();
            }
        }
        
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    s.findAnagrams("cbaebabacd", "abc");
    return 0;
}

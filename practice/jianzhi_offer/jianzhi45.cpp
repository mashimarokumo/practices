#include<vector>
#include<string>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> snums;
        vector<int> counts;
        string ans;
        if(nums.size() == 0) return ans;
        snums.push_back(to_string(nums[0]));
        counts.push_back(1);
        for (int j = 1; j < nums.size(); j++)
        {
            string s = to_string(nums[j]);
            bool flag = false;
            for (int i = 0; i < snums.size(); i++)
            {
                if(s < snums[i]) {
                    snums.insert(snums.begin() + i, s);
                    counts.insert(counts.begin()+i, 1);
                    flag = true;
                    break;
                }

                if(s == snums[i]){
                    counts[i]++;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                snums.push_back(s);
                counts.push_back(1);
            }
        }

        for (int i = 0; i < snums.size()-1; i++)
        {
            if(snums[i].length() != snums[i+1].length()){
                string a = snums[i] + snums[i+1];
                string b = snums[i+1] + snums[i];
                while(snums[i] + snums[i+1] > snums[i+1] + snums[i]){
                    string temp = snums[i];
                    snums[i] = snums[i+1];
                    snums[i+1] = temp;

                    int count = counts[i];
                    counts[i] = counts[i+1];
                    counts[i+1] = count;
                }
            }
            for (int j = 0; j < counts[i]; j++)
            {
                ans += snums[i];
            }
        }
        for (int i = 0; i < counts[snums.size()-1]; i++)
        {
            ans += snums[snums.size()-1];
        }
        
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> test = {1,1,1};
    cout << s.minNumber(test);
}
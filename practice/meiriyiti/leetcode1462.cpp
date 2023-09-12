#include<vector>

using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> pres = vector<vector<int>>(numCourses);
        vector<bool> finded = vector<bool>(numCourses);
        vector<int> outdegree = vector<int>(numCourses);
        vector<bool> ans;
        
        for (int i = 0; i < prerequisites.size(); i++)
        {
            pres[prerequisites[i][1]].push_back(prerequisites[i][0]);
            outdegree[prerequisites[i][0]] ++;
        }
        
        for (int i = 0; i < outdegree.size(); i++)
        {
            if(outdegree[i] == 0){
                findUp(i, finded, pres);
            }
        }
        

        for (int i = 0; i < queries.size(); i++)
        {
            for (int j = 0; j < pres[queries[i][1]].size(); j++)
            {
                if(pres[queries[i][1]][j] == queries[i][0]){
                    ans.push_back(true);
                    break;
                }
            }
                
            if(ans.size() != i + 1) ans.push_back(false);
        }
        
        return ans;
    }


    vector<int> findUp(int ele, vector<bool> finded, vector<vector<int>> pres){
        if(finded[ele]) return pres[ele];
        int size = pres[ele].size();
        for (int i = 0; i < size; i++)
        {
            vector<int> up = findUp(pres[ele][i], finded, pres);
            for (int j = 0; j < up.size(); j++)
            {
                pres[ele].push_back(up[j]);
            }
        }
        finded[ele] = true;
        return pres[ele];
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> a = {{1, 2},{2, 0}};
    vector<vector<int>> p =  {{1, 0}, {1, 2}};
    s.checkIfPrerequisite(3, a, p);
    return 0;
}

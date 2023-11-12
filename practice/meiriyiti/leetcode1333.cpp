#include<vector>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ids;
        for (int i = 0; i < restaurants.size(); i++)
        {
            if((veganFriendly && !restaurants[i][2]) || restaurants[i][3] > maxPrice || restaurants[i][4] > maxDistance){
                continue;
            }

            if(!ids.size()) ids.push_back(i);
            else{
                int s = ids.size();
                for (int j = 0; j < ids.size(); j++)
                {
                    if(restaurants[ids[j]][1] < restaurants[i][1]){
                        ids.insert(ids.begin() + j, i);
                        break;
                    }
                    else if(restaurants[ids[j]][1] == restaurants[i][1]){
                        if(restaurants[ids[j]][0] < restaurants[i][0]) ids.insert(ids.begin() + j, i);
                        else ids.insert(ids.begin() + j + 1, i);
                        break;
                    }
                }
                if(s == ids.size()) ids.push_back(i);
            }
        }
        
        for (int i = 0; i < ids.size(); i++)
        {
            ids[i] = restaurants[ids[i]][0];
        }
        
        return ids;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> res = {{1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1}};

    Solution s;
    s.filterRestaurants(res, 1, 50, 10);
    return 0;
}

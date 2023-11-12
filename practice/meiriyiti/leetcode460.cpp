#include<map>

using namespace std;

class LFUCache {
public:
    map<int, int> values;
    map<int, int> freqs;
    map<int, int> times;

    int curTime = 0;
    int cap;
    int curCap = 0;
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(values.count(key) == 1){
            times[key] = curTime;
            curTime++;
            freqs[key]++;
            return values[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(values.count(key) == 0){
            if(curCap >= cap){
                pair<int, int> p = {0, 200005};
                for (auto &&i : freqs)
                {
                    if(i.second < p.second){
                        p = i;
                    }else if(i.second == p.second){
                        if(times[i.first] < times[p.first]){
                            p = i;
                        }
                    }
                }
                times.erase(p.first);
                values.erase(p.first);
                freqs.erase(p.first);
            }
            else{
                curCap ++;
            }
            freqs[key] = 1;
        }
        freqs[key] ++;
        times[key] = curTime;
        curTime ++;
        values[key] = value;
    }
};

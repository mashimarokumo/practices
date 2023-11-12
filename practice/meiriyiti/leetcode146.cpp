#include<map>
#include<queue>

using namespace std;

class LRUCache {
public:
    map<int, int> values;
    map<int, int> times;

    int curTime = 0;
    int cap;
    int curCap = 0;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(values.count(key) == 1){
            times[key] = curTime;
            curTime++;
            return values[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(values.count(key) == 0){
            if(curCap >= cap){
                pair<int, int> p = {0, 200005};
                for (auto &&i : times)
                {
                    if(i.second < p.second){
                        p = i;
                    }
                }
                times.erase(p.first);
                values.erase(p.first);
            }
            else{
                curCap ++;
            }
        }
        times[key] = curTime;
        curTime ++;
        values[key] = value;
    }
};

int main(int argc, char const *argv[])
{
    LRUCache lru = LRUCache(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.put(3, 3);
    lru.get(1);
    return 0;
}

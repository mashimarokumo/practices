#include<vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if(minstack.size() != 0){
            if(x < minstack[minIndex]){
                minIndex = minstack.size();
            }
        }
        minstack.push_back(x);
    }
    
    void pop() {
        if(minstack.size() == 0) return;
        minstack.erase(minstack.end()-1);
        if(minIndex == minstack.size()){
            minIndex = 0;
            for (int i = 0; i < minstack.size(); i++)
            {
                if(minstack[i] < minstack[minIndex]){
                    minIndex = i;
                }
            }
            
        }
    }
    
    int top() {
        if(minstack.size() == 0) return -1;
        return minstack[minstack.size()-1];
    }
    
    int min() {
        if(minstack.size() == 0) return -1;
        return minstack[minIndex];
    }
private:
    vector<int> minstack;
    int minIndex = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
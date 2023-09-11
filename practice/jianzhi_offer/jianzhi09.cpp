#include<stack>

using namespace std;

class CQueue {
public:
    CQueue() {
        
    }
    
    void appendTail(int value) {
        if(a.empty()){
            while (!b.empty())
            {
                a.push(b.top());
                b.pop();
            }
        }
        a.push(value);
    }
    
    int deleteHead() {
        if(b.empty())
        {
            if(a.empty()){
                return -1;
            }
            while (!a.empty())
            {
                 b.push(a.top());
            a.pop();
            }
        }
        int value = b.top();
        b.pop();
        return value;
    }

private:
    stack<int> a;
    stack<int> b;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main(){
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    int param_2 = obj->deleteHead();
}
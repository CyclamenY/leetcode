#include <stack>

using namespace std;

class CQueue {
public:
    stack<int> mStack,sStack;
    CQueue() {
    }
    
    void appendTail(int value) {
        mStack.push(value);
    }
    
    int deleteHead() {
        if(mStack.size()==0) return -1;
        while(mStack.size()!=1) {
            sStack.push(mStack.top());
            mStack.pop();
        }
        int value=mStack.top();
        mStack.pop();
        while(sStack.size()!=0) {
            mStack.push(sStack.top());
            sStack.pop();
        }
        return value;
    }
};
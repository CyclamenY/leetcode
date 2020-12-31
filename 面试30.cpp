#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
private:
    stack<int> S;
    vector<int> vec;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        S.push(x);
        if(vec.empty() || x<=*vec.crbegin()) {
            vec.push_back(x);
        }
    }
    
    void pop() {
        if(*vec.crbegin()==S.top()) {
            vec.pop_back();
        }
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int min() {
        return *vec.crbegin();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout<<obj->min()<<" ";
    obj->pop();
    cout<<obj->top()<<" "<<obj->min();
}
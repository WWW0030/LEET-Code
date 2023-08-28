#include "bits/stdc++.h"
using namespace std;
class MyStack {
public:
    queue<int> a;
    MyStack() {
        a.push(0);
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        a.pop();
        int temp = 0;
        int front = a.front();
        while (front != 0) {
            a.push(temp);
            a.pop();
            temp = front;
            front = a.front();
        }
        return temp;
    }
    
    int top() {
        int topped = pop();
        a.push(topped);
        return topped;
    }
    
    bool empty() {
        return a.size() == 1;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
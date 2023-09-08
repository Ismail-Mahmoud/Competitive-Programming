// https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
    queue<int> Q;
    
    void move() {
        int sz = Q.size();
        while(sz > 1) {
            Q.push(Q.front());
            Q.pop();
            --sz;
        }
    }
    
public:
    MyStack() {}
    
    void push(int x) {
        Q.push(x);
        move();
    }
    
    int pop() {
        int t = top();
        Q.pop();
        return t;
    }
    
    int top() {
        return Q.front();
    }
    
    bool empty() {
        return Q.empty();
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
 
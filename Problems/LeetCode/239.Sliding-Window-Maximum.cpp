struct Stack{
    stack<pair<int, int>> stk;
    Stack(){
        stk.push(make_pair(INT_MIN, INT_MIN));
    }
    int getMax(){
        return stk.top().second;
    }
    int top(){
        return stk.top().first;
    }
    int size(){
        return stk.size() - 1;
    }
    bool empty(){
        return stk.size() == 1;
    }
    void push(int x){
        stk.push(make_pair(x, max(x, this->getMax())));
    }
    void pop(){
        stk.pop();
    }
};

struct Queue{
    Stack L, R;
    int getMax(){
        return max(L.getMax(), R.getMax());
    }
    int front(){
        if(L.empty()) this->move();
        return L.top();
    }
    int size(){
        return L.size() + R.size();
    }
    bool empty(){
        return L.empty() && R.empty();
    }
    void push(int x){
        R.push(x);
    }
    void pop(){
        if(L.empty()) this->move();
        L.pop();
    }
    void move(){
        while(!R.empty()){
            L.push(R.top());
            R.pop();
        }
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        if(a.empty()) return {};
        int n = a.size();
        vector<int> ret(n - k + 1);
        Queue q;
        for(int i = 0; i < k; ++i)
            q.push(a[i]);
        ret[0] = q.getMax();
        for(int i = k; i < n; ++i){
            q.pop();
            q.push(a[i]);
            ret[i - k + 1] = q.getMax();
        }
        return ret;
    }
};

// https://leetcode.com/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; ++i) {
            arr.push_back(arr[i]);
        }
        vector<int> nxt(n * 2, -1);
        stack<int> stk;
        for(int i = 0; i < n * 2; ++i) {
            while(!stk.empty() && arr[i] > arr[stk.top()]) {
                nxt[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
        return vector<int>(nxt.begin(), nxt.begin() + n);
    }
};
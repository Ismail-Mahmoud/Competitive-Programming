class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> stk;
        vector<int> prev_greater(n, -1);
        for(int i = n - 1; ~i; --i) {
            while(!stk.empty() && nums[i] > nums[stk.top()]) {
                prev_greater[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        vector<int> mn(n);
        mn[0] = nums[0];
        for(int i = 1; i < n; ++i) {
            mn[i] = min(mn[i - 1], nums[i]);
        }
        for(int i = 0; i < n; ++i) {
            int p = prev_greater[i];
            if(p <= 0) continue;
            if(mn[p - 1] < nums[i]) {
                return true;
            }
        }
        return false;
    }
};

// https://leetcode.com/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& A) {
        int n = A.size();
        vector<int> prev_greater(n, -1), pref_min(n);
        stack<int> S;
        pref_min[0] = A[0];
        S.push(n - 1);
        for(int i = n - 2; i >= 0; --i) {
            while(!S.empty() && A[i] > A[S.top()]) {
                prev_greater[S.top()] = i;
                S.pop();
            }
            S.push(i);
            int j = n - i - 1;
            pref_min[j] = min(pref_min[j - 1], A[j]);
        }
        for(int i = 0; i < n; ++i) {
            int p = prev_greater[i];
            if(p <= 0) continue;
            if(pref_min[p - 1] < A[i]) {
                return true;
            }
        }
        return false;
    }
};
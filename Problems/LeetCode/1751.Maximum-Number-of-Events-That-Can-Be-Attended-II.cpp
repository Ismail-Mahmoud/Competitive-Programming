// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/

class Solution {
public:
    vector<vector<int>> mem;
    static bool cmp(const vector<int>& A, const vector<int>& B) {
        return A[0] < B[0];
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), cmp);
        mem.resize(events.size());
        for(auto& v : mem) {
            v.resize(k + 1, -1);
        }
        return dp(0, k, events);
    }

    // dp(i, k) = max(dp(i + 1, k), val[i] + dp(i + 1, k - 1));
    int dp(int i, int k, vector<vector<int>>& events) {
        if(!k || i == events.size()) return 0;

        int& ret = mem[i][k];
        if(~ret) return ret;
        
        ret = dp(i + 1, k, events);

        auto cur_event = events[i];
        int nxt = upper_bound(events.begin(), events.end(), vector<int>({cur_event[1], 0, 0}), cmp) - events.begin();
        ret = max(ret, cur_event[2] + dp(nxt, k - 1, events));

        return ret;
    }
};
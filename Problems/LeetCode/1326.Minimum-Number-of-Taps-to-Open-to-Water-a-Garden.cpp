// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> segments(n + 1);
        for(int i = 0; i <= n; ++i) {
            int r = ranges[i];
            segments[i] = {i - r, i + r};
        }
        sort(segments.begin(), segments.end());
        int ans = 0, point = 0;
        for(int ptr = 0; ptr <= n && point < n;) {
            int max_end = INT_MIN;
            while(ptr <= n && segments[ptr].first <= point) {
                max_end = max(max_end, segments[ptr].second);
                ++ptr;
            }
            if(max_end <= point) {
                return -1;
            }
            point = max_end;
            ++ans;
        }
        return ans;
    }
};

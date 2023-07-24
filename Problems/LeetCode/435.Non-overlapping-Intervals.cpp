// https://leetcode.com/problems/non-overlapping-intervals/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& A, const vector<int>& B) {
            return A[1] < B[1];
        });
        vector<int> last({-100000, -100000});
        int ans = 0;
        for(const vector<int>& cur : intervals) {
            if(cur[0] < last[1]) {
                ++ans;
            }
            else {
                last = cur;
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int>& p1, const vector<int>& p2) {return p1[1] < p2[1];});
        int last = INT_MIN;
        int ans = 0;
        for(const vector<int>& p : pairs) {
            if(p[0] > last) {
                ++ans;
                last = p[1];
            }
        }
        return ans;
    }
};

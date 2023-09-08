// https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for(int r = 0; r < numRows; ++r) {
            ans[r].resize(r + 1);
            ans[r][0] = ans[r][r] = 1;
            for(int c = 1; c < r; ++c) {
                ans[r][c] = ans[r - 1][c - 1] + ans[r - 1][c];
            }
        }
        return ans;
    }
};

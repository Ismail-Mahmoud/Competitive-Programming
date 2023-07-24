// https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
    double mem[25][25][101];
    int dr[8] = {-2, -2, -1, -1,  1, 1,  2, 2};
    int dc[8] = {-1,  1, -2,  2, -2, 2, -1, 1};
public:
    double knightProbability(int n, int k, int row, int column) {
        memset(mem, -1, sizeof(mem));
        return dp(row, column, k, n);
    }

    double dp(int r, int c, int k, const int& n) {
        if(r < 0 || r >= n || c < 0 || c >= n) return 0;
        if(!k) return 1;

        double& ret = mem[r][c][k];
        if(ret == ret) return ret;

        ret = 0;
        for(int i = 0; i < 8; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            ret += dp(nr, nc, k - 1, n) / 8;
        }

        return ret;
    }
};
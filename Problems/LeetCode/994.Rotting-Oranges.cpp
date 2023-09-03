// https://leetcode.com/problems/rotting-oranges/

class Solution {
    int N, M;
    queue<pair<int, int>> Q;
    int di[4] = {-1, 1, 0, 0};
    int dj[4] = {0, 0, -1, 1};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        N = grid.size(), M = grid[0].size();
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(grid[i][j] == 2) {
                    Q.emplace(i, j);
                }
            }
        }
        return solve(grid);
    }

    int solve(vector<vector<int>>& grid) {
        int steps = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            ++steps;
            while(sz--) {
                pair<int, int> P = Q.front();
                Q.pop();
                int i = P.first, j = P.second;
                for(int k = 0; k < 4; ++k) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(inGrid(ni, nj, grid) && grid[ni][nj] == 1) {
                        Q.emplace(ni, nj);
                        grid[ni][nj] = 2;
                    }
                }
            }
        }
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return max(0, steps - 1);
    }

    bool inGrid(int i, int j, const vector<vector<int>>& grid) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
};

class Solution {
    int mem[100][100], N, M;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        N = obstacleGrid.size(); M = obstacleGrid[0].size();
        memset(mem, -1, sizeof(mem));
        return dp(0, 0, obstacleGrid);
    }
    int dp(int i, int j, const vector<vector<int>>& obstacleGrid) {
        if(i == N || j == M) return 0;
        if(i == N - 1 && j == M - 1) return !obstacleGrid[i][j];

        int& ret = mem[i][j];
        if(~ret) return ret;
        
        return ret = obstacleGrid[i][j]? 0 : dp(i + 1, j, obstacleGrid) + dp(i, j + 1, obstacleGrid);
    }
};

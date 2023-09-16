// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {
    int N, M, dist[100][100];
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    static const int OO = 0x3f3f3f3f;
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        N = heights.size(), M = heights[0].size();
        memset(dist, OO, sizeof(dist));
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > Q;
        Q.emplace(0, 0, 0);
        dist[0][0] = 0;
        while(!Q.empty()) {
            auto [d, i, j] = Q.top();
            Q.pop();
            if(i == N - 1 && j == M - 1) {
                return dist[i][j];
            }
            for(int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if(!valid(ni, nj)) continue;
                int d = max(dist[i][j], abs(heights[i][j] - heights[ni][nj]));
                if(d < dist[ni][nj]) {
                    dist[ni][nj] = d;
                    Q.emplace(d, ni, nj);
                }
            }
        }
        return -1;
    }

    bool valid(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
};

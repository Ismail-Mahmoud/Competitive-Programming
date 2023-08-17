// https://leetcode.com/problems/01-matrix/

class Solution {
    int N, M;
    int di[4] = {0, 0, -1, 1};
    int dj[4] = {-1, 1, 0, 0};
    vector<vector<int>> dist;
    queue<pair<int, int>> Q;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        N = mat.size(); M = mat[0].size();
        cout << N << " " << M << endl;
        dist.resize(N, vector<int>(M, INT_MAX));
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < M; ++j) {
                if(mat[i][j]) continue;
                Q.emplace(i, j);
                dist[i][j] = 0;
            }
        }
        bfs(mat);
        return dist;
    }
    void bfs(const vector<vector<int>>& mat) {
        while(!Q.empty()) {
            int sz = Q.size();
            while(sz--) {
                pair<int, int> P = Q.front();
                Q.pop();
                int i = P.first, j = P.second;
                for(int k = 0; k < 4; ++k) {
                    int ni = i + di[k];
                    int nj = j + dj[k];
                    if(!in_matrix(ni, nj) || dist[ni][nj] <= 1 + dist[i][j]) continue;
                    dist[ni][nj] = 1 + dist[i][j];
                    Q.emplace(ni, nj);
                }
            }
        }
    }
    bool in_matrix(int i, int j) {
        return i >= 0 && i < N && j >= 0 && j < M;
    }
};

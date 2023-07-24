// https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/

struct Node {
    int x, y, k;
};

bool vis[40][40][40*40+1];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        memset(vis, false, sizeof(vis));
        int n = grid.size(), m = grid[0].size();
        queue<Node> q;
        q.push({0, 0, k});
        vis[0][0][k] = true;
        int l = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                Node node = q.front();
                q.pop();
                int x = node.x, y = node.y, k = node.k;
                if(x == n - 1 && y == m - 1) {
                    return l;
                }
                for(int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if(!valid(nx, ny, n, m)) continue;
                    int nk = grid[nx][ny]? k - 1 : k;
                    if(nk < 0 || vis[nx][ny][nk]) continue;
                    vis[nx][ny][nk] = true;
                    q.push({nx, ny, nk});
                }
            }
            ++l;
        }
        return -1;
    }
};
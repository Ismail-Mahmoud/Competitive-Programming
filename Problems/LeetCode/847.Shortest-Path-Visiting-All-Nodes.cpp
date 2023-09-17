// https://leetcode.com/problems/shortest-path-visiting-all-nodes/

class Solution {
    bool vis[12][1 << 12];
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int N = graph.size();
        queue<pair<int, int>> Q;
        for(int i = 0; i < N; ++i) {
            Q.emplace(i, 1 << i);
            vis[i][1 << i] = true;
        }
        int steps = 0;
        while(!Q.empty()) {
            int sz = Q.size();
            ++steps;
            while(sz--) {
                auto [u, mask] = Q.front();
                Q.pop();
                if(__builtin_popcount(mask) == N) {
                    return steps - 1;
                }
                for(int v : graph[u]) {
                    int new_mask = mask | (1 << v);
                    if(vis[v][new_mask]) continue;
                    vis[v][new_mask] = true;
                    Q.emplace(v, new_mask);
                }
            }
        }
        return -1;
    }
};

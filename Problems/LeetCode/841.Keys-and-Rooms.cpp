// https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    vector<vector<int>> adj;
    bool vis[1005];
    int cnt = 0;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        adj = rooms;
        dfs(0);
        return cnt == rooms.size();
    }
    void dfs(int u) {
        ++cnt;
        vis[u] = true;
        for(int v : adj[u]) {
            if(!vis[v]) {
                dfs(v);
            }
        }
    }
};
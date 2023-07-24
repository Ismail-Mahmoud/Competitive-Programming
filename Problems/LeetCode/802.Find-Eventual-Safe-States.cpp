// https://leetcode.com/problems/find-eventual-safe-states/

class Solution {
public:
    bool vis[10000], is_safe[10000];
    vector<int> ans;
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int u = 0; u < graph.size(); ++u) {
            dfs(u, graph);
            if(is_safe[u]) {
                ans.push_back(u);
            }
        }
        return ans;
    }
    bool dfs(int u, vector<vector<int>>& graph) {
        if(vis[u]) {
            return is_safe[u];
        }
        vis[u] = true;
        int safe_paths = 0;
        for(int v : graph[u]) {
            safe_paths += dfs(v, graph);
        }
        return is_safe[u] = safe_paths == graph[u].size();
    }
};
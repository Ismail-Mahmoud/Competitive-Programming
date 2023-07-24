// https://leetcode.com/problems/all-paths-from-source-to-target/

class Solution {
    vector<vector<int>> ans;
    void dfs(int u, const vector<vector<int>>& graph, vector<int>& path) {
        path.push_back(u);
        if(u == (int)graph.size() - 1) {
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(int v : graph[u]) {
            dfs(v, graph, path);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        dfs(0, graph, path);
        return ans;
    }
};
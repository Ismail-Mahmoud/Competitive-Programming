// https://leetcode.com/problems/maximal-network-rank/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> edge(n, vector<bool>(n, false));
        for(const vector<int>& road : roads) {
            int a = road[0], b = road[1];
            ++degree[a], ++degree[b];
            edge[a][b] = edge[b][a] = true;
        }
        int ans = 0;
        for(int a = 0; a < n; ++a) {
            for(int b = a + 1; b < n; ++b) {
                ans = max(ans, degree[a] + degree[b] - edge[a][b]);
            }
        }
        return ans;
    }
};

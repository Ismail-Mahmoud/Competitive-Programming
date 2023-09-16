// https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
    unordered_map<string, vector<string>> G;
    vector<string> ans;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(const vector<string>& t : tickets) {
            G[t[0]].push_back(t[1]);
        }
        for(auto& [s, vec] : G) {
            sort(vec.rbegin(), vec.rend());
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void dfs(string u) {
        while(!G[u].empty()) {
            string v = G[u].back();
            G[u].pop_back();
            dfs(v);
        }
        ans.push_back(u);
    }
};

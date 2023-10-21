// https://leetcode.com/problems/number-of-flowers-in-full-bloom/

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> F;
        F[0] = 0;
        for(const vector<int>& v : flowers) {
            ++F[v[0]];
            --F[v[1] + 1];
        }
        for(auto it = next(F.begin()); it != F.end(); ++it) {
            it->second += prev(it)->second;
        }
        vector<int> ans;
        ans.reserve(people.size());
        for(int p : people) {
            auto it = prev(F.upper_bound(p));
            ans.push_back(it->second);
        }
        return ans;
    }
};

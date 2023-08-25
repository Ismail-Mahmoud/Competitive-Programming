// https://leetcode.com/problems/reorganize-string/

class Solution {
public:
    string reorganizeString(string s) {
        vector<int> F(26, 0);
        for(char ch : s) {
            ++F[ch - 'a'];
        }
        set<pair<int, char>, greater<pair<int, char>>> S;
        for(int i = 0; i < 26; ++i) {
            if(F[i]) S.emplace(F[i], 'a' + i);
        }
        string ans;
        while(!S.empty()) {
            auto it = S.begin();
            if(!ans.empty() && it->second == ans.back()) {
                ++it;
                if(it == S.end()) return "";
            }
            ans.push_back(it->second);
            if(it->first > 1) {
                S.emplace(it->first - 1, it->second);
            }
            S.erase(it);
        }
        return ans;
    }
};

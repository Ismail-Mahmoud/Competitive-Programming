// https://leetcode.com/problems/unique-number-of-occurrences/

class Solution {
public:
    map<int, int> M;
    set<int> S;
    bool uniqueOccurrences(vector<int>& arr) {
        for(int x : arr) {
            ++M[x];
        }
        for(auto& [x, cnt] : M) {
            S.insert(cnt);
        }
        return S.size() == M.size();
    }
};
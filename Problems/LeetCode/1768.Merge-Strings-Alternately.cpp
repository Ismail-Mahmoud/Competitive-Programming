// https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int n = min(word1.size(), word2.size());
        string ans = "";
        for(; i < n; ++i) {
            ans += word1[i];
            ans += word2[i];
        }
        for(int j = i; j < word1.size(); ++j) {
            ans += word1[j];
        }
        for(int j = i; j < word2.size(); ++j) {
            ans += word2[j];
        }
        return ans;
    }
};
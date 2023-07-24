// https://leetcode.com/problems/is-subsequence/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        for(int i = 0, j = 0; i < s.size(); ++i, ++j) {
            while(j < t.size() && s[i] != t[j]) ++j;
            if(j == t.size()) return false;
        }
        return true;
    }
};
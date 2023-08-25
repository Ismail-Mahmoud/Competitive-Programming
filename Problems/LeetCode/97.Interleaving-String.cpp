// https://leetcode.com/problems/interleaving-string/

class Solution {
    int mem[100][100];
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        memset(mem, -1, sizeof(mem));
        return dp(0, 0, 0, s1, s2, s3);
    }
    bool dp(int i1, int i2, int i3, const string& s1, const string& s2, const string& s3) {
        if(i1 == s1.size()) return s2.substr(i2) == s3.substr(i3);
        if(i2 == s2.size()) return s1.substr(i1) == s3.substr(i3);

        int& ret = mem[i1][i2];
        if(~ret) return ret;

        ret = false;
        if(s1[i1] == s3[i3]) {
            ret |= dp(i1 + 1, i2, i3 + 1, s1, s2, s3);
        }
        if(s2[i2] == s3[i3]) {
            ret |= dp(i1, i2 + 1, i3 + 1, s1, s2, s3);
        }

        return ret;
    }
};

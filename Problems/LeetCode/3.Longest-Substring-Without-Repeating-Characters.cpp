// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        bitset<128> B;
        for(int l = 0, r = 0; r < s.size(); ++r) {
            while(B[s[r]]) {
                B.reset(s[l++]);
            }
            B.set(s[r]);
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> idx;
        for(int i = 0, cnt = 0; i < s.size(); ++i) {
            ++cnt;
            if(idx.contains(s[i])) {
                cnt = min(cnt, i - idx[s[i]]);
            }
            idx[s[i]] = i;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> freq;
        unordered_set<int> freqs;
        for(char ch : s) {
            ++freq[ch];
        }
        int ans = 0;
        for(auto& [ch, f] : freq) {
            while(f && !freqs.insert(f).second) {
                --f;
                ++ans;
            }
        }
        return ans;
    }
};

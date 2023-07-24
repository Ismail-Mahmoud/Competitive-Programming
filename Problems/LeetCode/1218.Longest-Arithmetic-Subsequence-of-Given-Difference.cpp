// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    static const int N = 2e4;
    int longest_subsequence_ending_at[(N << 1) + 5];
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0;
        for(int num : arr) {
            num += N;
            longest_subsequence_ending_at[num] = 1 + longest_subsequence_ending_at[num - difference];
            ans = max(ans, longest_subsequence_ending_at[num]);
        }
        return ans;
    }
};
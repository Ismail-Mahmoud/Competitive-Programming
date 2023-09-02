# https://leetcode.com/problems/extra-characters-in-a-string/

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        n = len(s)
        dp = [None] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            dp[i] = 1 + dp[i - 1]
            for p in range(i):
                if s[p:i] in dictionary:
                    dp[i] = min(dp[i], dp[p])
        return dp[n]

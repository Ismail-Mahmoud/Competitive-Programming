class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        words.sort(key=lambda word: len(word))
        dp = {}
        for word in words:
            dp[word] = 1
            for i in range(len(word)):
                predecessor = word[:i] + word[i+1:]
                dp[word] = max(dp[word], 1 + dp.get(predecessor, 0))
        return max(dp.values())

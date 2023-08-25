# https://leetcode.com/problems/repeated-substring-pattern/

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        l = len(s)
        for d in range(1, l // 2 + 1):
            if l % d == 0 and s[:d] * (l // d) == s:
                return True
            d += 1
        return False

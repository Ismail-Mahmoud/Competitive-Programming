class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        ans = ""
        last_occ = {}
        for i, c in enumerate(s):
            last_occ[c] = i
        for i, c in enumerate(s):
            if c in ans:
                continue
            while(ans and ans[-1] > c and last_occ[ans[-1]] > i):
                ans = ans[:-1]
            ans += c
        return ans

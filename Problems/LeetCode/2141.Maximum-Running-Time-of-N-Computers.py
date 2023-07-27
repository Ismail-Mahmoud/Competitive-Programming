# https://leetcode.com/problems/maximum-running-time-of-n-computers/

class Solution:
    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        def check(target):
            total = sum(min(target, time) for time in batteries)
            return n * target <= total
        
        l, r = 1, sum(batteries) // n
        while l < r:
            m = (l + r + 1) // 2
            if check(m):
                l = m
            else:
                r = m - 1
        return l

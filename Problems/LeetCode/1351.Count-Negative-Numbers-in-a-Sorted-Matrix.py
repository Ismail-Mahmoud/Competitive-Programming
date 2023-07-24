# https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        ans = 0
        for i in range(n):
            ans += self.count_negatives(grid[i])
        return ans

    def count_negatives(self, lst: List[int]) -> int:
        n = len(lst)
        l, r = 0, n - 1
        # Get the index of the first negative number
        while l < r:
            m = (l + r) // 2
            if lst[m] >= 0:
                l = m + 1
            else:
                r = m
        l += lst[l] >= 0
        return n - l
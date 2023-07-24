# https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        neg = self.count_negatives(nums)
        pos = self.count_positives(nums)
        return max(neg, pos)
        
    def count_negatives(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            m = (l + r + 1) // 2
            if nums[m] < 0:
                l = m
            else:
                r = m - 1
        l -= nums[l] >= 0
        return l + 1

    def count_positives(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = 0, n - 1
        while l < r:
            m = (l + r) // 2
            if nums[m] <= 0:
                l = m + 1
            else:
                r = m
        l += nums[l] <= 0
        return n - l
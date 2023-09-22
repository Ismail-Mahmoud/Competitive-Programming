# https://leetcode.com/problems/find-the-duplicate-number/

class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        lo, hi = 0, len(nums)
        while lo < hi:
            mid = (lo + hi) // 2
            cnt = sum(x <= mid for x in nums)
            if cnt <= mid:
                lo = mid + 1
            else:
                hi = mid
        return lo

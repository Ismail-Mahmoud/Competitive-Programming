# https://leetcode.com/problems/largest-divisible-subset/

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        N = len(nums)
        dp = [1] * N
        maxi = 0

        for i in range(N):
            for p in range(i):
                if nums[i] % nums[p] == 0:
                    dp[i] = max(dp[i], 1 + dp[p])
            if dp[i] > dp[maxi]:
                maxi = i

        def get_prev(i):
            for p in range(i):
                if nums[i] % nums[p] == 0 and dp[i] == 1 + dp[p]:
                    return p

        i = maxi
        ans = [nums[maxi]]
        while (i := get_prev(i)) is not None:
            ans.append(nums[i])

        return ans

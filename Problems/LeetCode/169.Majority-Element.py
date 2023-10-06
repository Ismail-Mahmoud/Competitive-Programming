# https://leetcode.com/problems/majority-element/

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        candidate, cnt = None, 0
        for num in nums:
            if cnt == 0:
                candidate = num
                cnt = 1
            else:
                cnt += 1 if num == candidate else -1
        # if nums.count(candidate) <= len(nums) // 2:
        #     return None
        return candidate

# https://leetcode.com/problems/majority-element-ii/

class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        candidates = [None, None]   # arbitrary values
        cnt = [0, 0]
        for num in nums:
            if num == candidates[0]:
                cnt[0] += 1
            elif num == candidates[1]:
                cnt[1] += 1
            elif not cnt[0]:
                candidates[0], cnt[0] = num, 1
            elif not cnt[1]:
                candidates[1], cnt[1] = num, 1
            else:
                cnt[0] -= 1
                cnt[1] -= 1
        return [cand for cand in candidates if nums.count(cand) > len(nums) // 3]

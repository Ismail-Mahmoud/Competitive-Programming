class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        return any((
            all(nums[i] <= nums[i + 1] for i in range(len(nums) - 1)),
            all(nums[i] >= nums[i + 1] for i in range(len(nums) - 1))
        ))

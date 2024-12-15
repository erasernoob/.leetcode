#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)

        def robRange(start_index, end_index):
            
            dp = [0] * (end_index + 1)
            dp[start_index] = nums[start_index]
            dp[start_index + 1] = max(nums[start_index], nums[start_index + 1])
            
            for i in range(start_index + 2, end_index + 1):
                dp[i] = max(dp[i-2] + nums[i], dp[i - 1])
            return dp[end_index]
        return max(robRange(0, len(nums) - 2), robRange(1, len(nums) - 1))


        
# @lc code=end


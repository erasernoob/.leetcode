#
# @lc app=leetcode.cn id=198 lang=python3
#
# [198] 打家劫舍
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]

        def robRange(start_index, end_index):
            
            dp = [0] * (end_index + 1)
            dp[start_index] = nums[start_index]
            dp[start_index + 1] = max(nums[start_index], nums[start_index + 1])
            
            for i in range(start_index + 2, end_index + 1):
                dp[i] = max(dp[i-2] + nums[i], dp[i - 1])
            return dp[end_index]
        res = robRange(0, len(nums) - 1)
        return res

        

        
# @lc code=end


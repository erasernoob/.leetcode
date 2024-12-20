#
# @lc app=leetcode.cn id=53 lang=python3
#
# [53] 最大子数组和
#

# @lc code=start
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        dp = [0] * (len(nums))
        dp[0] = nums[0]

        for i in range(1, len(nums)):
            if dp[i-1] > 0:
                dp[i] = dp[i-1] + nums[i]
            else: dp[i] = nums[i]
        print(dp)
        return max(dp)

            
            
        

        
# @lc code=end


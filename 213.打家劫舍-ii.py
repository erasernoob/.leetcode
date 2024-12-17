#
# @lc app=leetcode.cn id=213 lang=python3
#
# [213] 打家劫舍 II
#

# @lc code=start
class Solution:
    def rob(self, nums: List[int]) -> int:
        # 状态，偷或者不偷
        # dp[i] 代表的是到第i个房屋能够获得的最大的价值
        # 递推关系： dp[i] = max(do[i - 2] + nums[i], dp[i - 1])
        # 初始化， dp[0] = nums[0] dp[1] = max(dp[0], dp[1])
        if len(nums) == 0:
            return 0
        if len(nums) == 1:
            return nums[0]
        if len(nums) == 2:
            return max(nums)

        def rob_helper(start_index, end_index):
            dp = [0] * (end_index + 1)
            dp[start_index] = nums[start_index]
            dp[start_index + 1] =  max(nums[start_index + 1], dp[start_index])

            for i in range(start_index + 2, end_index + 1):
                dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
            
            # print(dp)
            return dp[end_index]
        return max(rob_helper(1, len(nums) - 1), rob_helper(0, len(nums) - 2))
        
# @lc code=end


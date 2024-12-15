#
# @lc app=leetcode.cn id=416 lang=python3
#
# [416] 分割等和子集
#

# @lc code=start
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        # 分割等和子集，求背包最多能够装多少
        # 如果最多能够装的和，等于target那么就满足要求
        if sum(nums) % 2 != 0: 
            return False
        target = (sum(nums) // 2) 

        dp = [0] * (target + 1)
        # dp[0] = 1

        for i in range(len(nums)):
            for j in range(target, nums[i] - 1, -1):
                dp[j] = max(dp[j], dp[j -nums[i]] + nums[i])
        
        return dp[target] == target


        
        
        
        


        
        
                


        

# @lc code=end


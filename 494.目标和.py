#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        Sum = sum(nums) + target
        if Sum % 2 != 0 or abs(target) > sum(nums): return 0
        bag_weight = (Sum) // 2
        # dp[j] 代表的是 背包容量为j的能够装下的物品（价值）
        # dp[0] = 1
        # dp[j] = max(dp[j - 1], dp[j-weight[i]])
        # 这道题可以转化为01背包问题
        # 假设所有符号为+的元素和为x，符号为-的元素和为y
        # 那么 x + y = sum, x - y = target
        # 可以求得 x = (sum + target)/2
        # 问题转化为:装满容量为x的背包有几种方法

        dp = [0] * (bag_weight + 1)
        

        dp[0] = 1

        for i in range(0, len(nums)):
            for j in range(bag_weight, nums[i] - 1, -1):
                dp[j] = dp[j] + dp[j-nums[i]]
        return dp[bag_weight]

            
        

    
                

            



        
        
        
# @lc code=end


#
# @lc app=leetcode.cn id=746 lang=python3
#
# [746] 使用最小花费爬楼梯
#

# @lc code=start
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        # 1. dp[i] 是爬到第i个楼梯所需要的代价
        # 递推关系 dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]) 
        # 初始化 dp[0] = 0 dp[1] = 0
        # 从前向后的遍历顺序 
        # 
        dp = [0 for _ in range(len(cost) + 1)]
        for i in range(2, len(cost) + 1):
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2])
        return dp[len(cost)]

        
        
        
            
        # 



        
        
# @lc code=end


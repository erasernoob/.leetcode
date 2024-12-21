#
# @lc app=leetcode.cn id=309 lang=python3
#
# [309] 买卖股票的最佳时机含冷冻期
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 有四个状态，形成了一个四个状态相互转化的有限状态机
        # 0 此时持有股票
        # 1 此时未持有股票
        # 2 刚好今天卖出股票
        # 3 处于冷冻期
        dp = [[0]* 4 for _ in range(len(prices))]
        # 初始化
        dp[0][0] = -prices[0]
        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]) - prices[i])
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3])
            dp[i][2] = dp[i - 1][0] + prices[i]
            dp[i][3] = dp[i - 1][2]
        
        return max(dp[-1][1], dp[-1][2], dp[-1][3])
        
        
        
        

        
        
# @lc code=end


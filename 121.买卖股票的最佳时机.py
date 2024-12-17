#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 首先递归六部曲第一部，找到两种不同的状态
        # 持有，或者是不持有
        # dp[i][0] 代表的是当前持有i股票手上的现金数
        # dp[i][1] 代表的是当前未持有i股票手上有的现金数目
        # dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]) 保持不变
        # 在第i天卖出股票，就代表的是没有持有股票
        # dp[i][1] = dp[i - 1][1]
        # 初始化： dp[0][0] = -prices[0] dp[0][1] = 0

        dp = [[0 for _ in range(2)] for _ in range(len(prices))]
        
        dp[0][0] = -prices[0]
        dp[0][1] = 0

        for i in range(1, len(prices)):
            dp[i][1] = max(dp[ i - 1][1], prices[i] +  dp[i - 1][0])
            dp[i][0] = max(dp[i - 1][0], -prices[i])
        
        return dp[len(prices) - 1][1]


        

            
            

        
# @lc code=end


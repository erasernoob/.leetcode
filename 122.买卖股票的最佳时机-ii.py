#
# @lc app=leetcode.cn id=122 lang=python3
#
# [122] 买卖股票的最佳时机 II
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # 支持多次对股票进行买卖
        
        dp = [[0 for _ in range(2)] for _ in range(len(prices))]
        
        dp[0][0] = 0
        dp[0][1] = -prices[0]

        for i in range(1, len(prices)):
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]+ prices[i])
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1])
        
        return dp[-1][0]
        


        
# @lc code=end


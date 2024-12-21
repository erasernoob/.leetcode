#
# @lc app=leetcode.cn id=188 lang=python3
#
# [188] 买卖股票的最佳时机 IV
#

# @lc code=start
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        # 限制了可以买卖不超过k次数
        # 状态还是一样的，从大的层面来说只有两个状态，当前持有股票，还是没有持有股票
        dp = [[0 for _ in range(2 * k + 1)] for _ in range(len(prices))]

        # 奇数为当前持有股票
        for i in range(1, 2 * k + 1, 2):
            dp[0][i] = -prices[i]
        
        # 还是从奇数中开始
        for i in range(1, len(prices)):
            dp[i][0] = dp[i - 1][0]
            for j in range(2, 2 * k + 1, 2):
                dp[i][j - 1] = max(dp[i - 1][j - 1], dp[i - 1][j - 1 - 1] - prices[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i])
        print(dp)


        
        
        


        
# @lc code=end


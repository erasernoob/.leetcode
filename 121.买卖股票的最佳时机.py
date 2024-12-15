#
# @lc app=leetcode.cn id=121 lang=python3
#
# [121] 买卖股票的最佳时机
#

# @lc code=start
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        cur = res = 0
        max = -100000
        for i in range(1, len(prices)):
            cur += prices[i] - prices[i - 1]
            if cur < 0:
                cur =  0
            if cur > max:
                max = cur
        return max
            

        
# @lc code=end


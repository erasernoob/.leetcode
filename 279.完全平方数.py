#
# @lc app=leetcode.cn id=279 lang=python3
#
# [279] 完全平方数
#

# @lc code=start
class Solution:
    def numSquares(self, n: int) -> int:
        # dp[i] 代表的是对于i等于完全平方数的和的个数
        # 本质上还是挑选在一个数组中选择，和为target的最小方法数
        # 初始化nums数组
        
        dp = [214748647] * (n + 1)
        dp[0] = 0

        for i in range(1, n):
            for j in range(n + 1):
                if j >= i * i:
                    dp[j] = min(dp[j], dp[j - i * i] + 1)
        return dp[n]
        
# @lc code=end


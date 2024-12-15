#
# @lc app=leetcode.cn id=343 lang=python3
#
# [343] 整数拆分
#

# @lc code=start
class Solution:
    def integerBreak(self, n: int) -> int:
        # dp[i] 代表的是i拆分成k个正整数的和后的最大化乘积 
        # 两种情况 一种是 dp[j] * (i - j) 或者 dp[j] * dp[i-j]
        # dp[i] 对于 从1开始遍历的j到n/2来说，dp[i] = max(dp[i], max(dp[j] * dp[i-j], dp[j] * (i-j)) ) // 在这些之中挑选最大的
        dp = [0 for _ in range(n + 1)]
        # 初始化 dp[0]
        dp[0] = 0
        dp[1] = 0
        dp[2] = 1
        
        for i in range(n + 1):
            for j in range(1, i):
                dp[i] = max(dp[i], max(dp[j] * dp[i-j], dp[j] * (i-j)))
        print(dp)
        return dp[n]
        
        
        
        
        
        
# @lc code=end

#
# @lc app=leetcode.cn id=509 lang=python3
#
# [509] 斐波那契数
#

# @lc code=start
class Solution:
    def fib(self, n: int) -> int:
        if n <= 1: return n
        dp = [0] * 2
        dp[0] = 0
        dp[1] = 1
        for i in range(2, n+1):
            tmp = dp[1]
            dp[1] = dp[1] + dp[0] 
            dp[0] = tmp
        return dp[1]
        
            


        
# @lc code=end


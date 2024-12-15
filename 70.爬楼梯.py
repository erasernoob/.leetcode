#
# @lc app=leetcode.cn id=70 lang=python3
#
# [70] 爬楼梯
#

# @lc code=start
class Solution:
    def climbStairs(self, n: int) -> int:
        # dp[i] 代表到达第i阶的方法数
        # dp[i] = dp[i-1] + dp[i-2] 确定递推公式：当前层的方法数等于从爬一个楼梯的数目加上爬两个楼梯的方法数目的和
        # 初始化dp dp[0] = 0 dp[1] = 1 dp[2] = 2
        # 确定遍历顺序，从前到后遍历 -> 
        # 举例推导dp数组 当在第3阶的时候 dp[3] = dp[2] + dp[1] = 3 1.111 2. 12 3.21
        dp = [0] * (n + 1)
        dp[0] = 1
        
        for i in (1, n + 1):
            for j in (i, n + 1):
                if j - i >= 0:
                    dp[j] = dp[j] + dp[j - i]
        return dp[n]

        
# @lc code=end


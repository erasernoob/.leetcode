#
# @lc app=leetcode.cn id=62 lang=python3
#
# [62] 不同路径
#

# @lc code=start
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0] * n] * m
        # dp[i][j] 表示到（i,j）的路径条数 答案 = dp[m][n]
        # 确定递推关系: dp[i][j] = dp[i-1][j] + dp[i][j-1]
        # 初始化： 所有第一排和第一行的都应该初始化成1
        for i in range(m):
            dp[i][0] = 1
        for j in range(n):
            dp[0][j] = 1
        # 确定遍历顺序 先遍历m或者n都可以的
        for i in range(1,m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
        return dp[m-1][n-1]


        
# @lc code=end


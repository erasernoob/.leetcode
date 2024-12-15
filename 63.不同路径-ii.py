#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#

# @lc code=start
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        # 你问怎么在动态规划中去掉路径？
        # dp[i][j] 代表的是到达该点的所有的移动路径，
        # 递推关系 = dp[i][j] = dp[i][j-1] +  dp[i][j-1]
        # dp数组的初始化，按照逻辑来说代表的是该点的所有的路径条数，那么根本就到不了这个点所以就直接这个初始化为0,并且第一个列和第一行都是只有一条路径才能到达
        # 从行到列的一行行的遍历
        # 按照矩阵的举例
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0 for _ in range(n)] for _ in range(m)] 
        for i in range(m):
            if obstacleGrid[i][0] == 0:
                dp[i][0] = 1
            else: break
        for j in range(n):
            if obstacleGrid[0][j] == 0:
                dp[0][j] = 1
            else:
                break
        print(dp)
                

        for i in range(1, m):
            for j in range(1, n):
                if obstacleGrid[i][j] == 0:
                    dp[i][j] = dp[i][j-1] + dp[i-1][j]
        print(dp)
        return dp[m-1][n-1]
        
        

        
         
                
        
        
# @lc code=end


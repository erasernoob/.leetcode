#
# @lc app=leetcode.cn id=474 lang=python3
#
# [474] 一和零
#

# @lc code=start
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # dp[i][j] 代表的是最多有i个0和j个1的最大子集的个数
        # dp[i][j] = max(dp[i][j], dp[i - zero_num][j - one_num] + 1)
        # dp[i][j] = 0
        # 这是一个重量为二维的01背包的题目

        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

        
        # 遍历整个字符串数组
        for str in strs:
            zero_num = one_num = 0
            for i in range(len(str)):
                if(str[i] == '0'):
                    zero_num += 1
                else: one_num += 1
            
            # 开始状态转移
            # 遍历背包容量并且从后往前开始遍历！ 
            for i in range(m, zero_num - 1, -1):
                for j in range(n, one_num - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - zero_num][j - one_num] + 1)
        return dp[m][n] 

            
        
        
        
# @lc code=end


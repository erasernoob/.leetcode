#
# @lc app=leetcode.cn id=96 lang=python3
#
# [96] 不同的二叉搜索树
#

# @lc code=start
class Solution:
    def numTrees(self, n: int) -> int:
        # dp[i] 代表整数n能够组成的不同的二叉搜索树的种数
        dp = [0] * (n + 1)
        dp[0] = 1
        
        for i in range(1, n + 1):
            for j in range(1, i + 1):
                # dp[以j为头节点左子树] * dp[j为头节点右子树的数目]
                dp[i] += dp[j - 1]  * dp[i - j]
        print(dp)
        return dp[n]

        
        


                

        


# @lc code=end


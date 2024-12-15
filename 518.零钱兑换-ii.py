#
# @lc app=leetcode.cn id=518 lang=python3
#
# [518] 零钱兑换 II
#

# @lc code=start
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        # amount = bag_weight
        # and the coins is the value
        # dp[j] represntes there are dp[j] ways to get to j
        # 所有的排列组合问题，都应该dp[0] 初始化为1
        # 这不是一个纯背包问题，是一个排列组合问题
        # 纯完全背包追求的是，背包最终被装满
        # 这里追求的是装当个背包容量的个数
        # 完全背包的排列组合，滚动数组从前向后滚
        dp = [0 for _ in range(amount + 1)]

        dp[0] = 1

        for i in range(len(coins)):
            for j in range(coins[i], amount + 1):
                dp[j] = dp[j] + dp[j - coins[i]]
        print(dp)
        return dp[amount]
        

        
# @lc code=end


#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        # 因为硬币的数量是无限的，所以 -> 完全背包
        # 要找的最小的硬币的个数
        # dp[i]代表的是凑成总金额i所需要的最少的硬币的个数
        # 完全背包中，最大价值的体现
        # 填满整个整数amount总金额，使用j下标体现，也就是背包容量j
        # 思路： dp[j - coin[i]] + 1 这是最少的 ,每一轮次的选择都需要最小
        # dp[0] = 0

        dp = [0] * (amount + 1)
        
        for coin in coins:
            if coin <= amount:
                dp[coin] = 1

        for i in range(len(coins)):
            for j in range(amount + 1):
                if j >= coins[i] and dp[j] != 0:
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1)
                elif dp[j] == 0 and j >= coins[i]:
                    dp[j] = dp[j - coins[i]] + 1
        print(dp)
        return dp[amount] if dp[amount] != 0 else -1


        
# @lc code=end


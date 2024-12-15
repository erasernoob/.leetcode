#
# @lc app=leetcode.cn id=377 lang=python3
#
# [377] 组合总和 Ⅳ
#

# @lc code=start
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        # 完全背包题目
        # 如果先遍历背包容量，那么就是排列
        # 如果先遍历物品，那么就是组合
        # dp[j] 代表的是总和为j的元素的组合的个数 
        dp = [0] * (target + 1)
        
        dp[0] = 1

        for j in range(target + 1):
            for i in range(len(nums)):
                if j - nums[i] >= 0:
                    dp[j] = dp[j] + dp[j - nums[i]]
        return dp[target]

        



        
# @lc code=end


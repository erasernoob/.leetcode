#
# @lc app=leetcode.cn id=135 lang=python3
#
# [135] 分发糖果
#

# @lc code=start
class Solution:
    def candy(self, ratings: List[int]) -> int:
        candy = [1] * len(ratings)
        for i in range(len(ratings) - 1):
            if ratings[i] < ratings[i + 1]:
                candy[i + 1] = max(candy[i + 1], candy[i] + 1)
        for j in range(len(ratings) - 1, 0, -1):
            if ratings[j] < ratings[j - 1]:
                candy[j - 1] = max(candy[j - 1], candy[j] + 1)
        return sum(candy)


        
        
# @lc code=end


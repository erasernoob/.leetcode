#
# @lc app=leetcode.cn id=1049 lang=python3
#
# [1049] 最后一块石头的重量 II
#

# @lc code=start
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        # 这是一个从序列中挑选子序列使得和接近target的题目
        # 使用01背包，因为最后不管你怎么撞都是在相当于两个子序列在撞
        # 两个数相撞 -> 两个子序列相撞
        target = sum
        
        
# @lc code=end


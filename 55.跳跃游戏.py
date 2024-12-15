#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#

# @lc code=start
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        left = 0
        right = 0
        for i in range(len(nums)):
            if i <= right and i >= left:
                if right <= i + nums[i]:
                    right = i + nums[i]
        return right >= len(nums) - 1;
            
        
# @lc code=end


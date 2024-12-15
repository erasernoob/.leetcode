#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#

# @lc code=start
class Solution:
    def jump(self, nums: List[int]) -> int:
        cur = 0
        max = 0
        cnt = 0
        for i in range(len(nums) - 1):
            if max < nums[i] + i:
                max = nums[i] + i
            if i == cur:
                cur = max
                cnt += 1
        return cnt
                
        
        
# @lc code=end


#
# @lc app=leetcode.cn id=337 lang=python3
#
# [337] 打家劫舍 III
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
       # dp[0, 1] 代表的是偷父亲，或者不偷
        def rob_range(root: Optional[TreeNode]):
            # 后序遍历
            if root == None: return [0, 0]
            val_left = rob_range(root.left)
            val_right = rob_range(root.right)
            # 偷 or 不偷
            val_root = [0] * 2
            # 不偷
            val_root[0] = max(val_right) + max(val_left) 
            # 偷 不偷左右孩
            val_root[1] = val_left[0] + val_right[0] + root.val

            return val_root
        return max(rob_range(root))



    
        
        
# @lc code=end


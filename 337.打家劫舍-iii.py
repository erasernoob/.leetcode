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
        # 状态：父节点偷还是不偷
        # dp[2] = [0, 1] 代表的是偷得到的最大值， 和不偷得到的最大值

        memory = {}
        # 使用常规的树的后序遍历来做
        def recur_rob(node: Optional[TreeNode]):
            if node == None: return 0
            if node.left == None and node.right == None: return node.val
            if node in memory:
                return memory[node]

            val_root_1 = node.val
            if node.left != None:
                val_root_1 += recur_rob(node.left.right) + recur_rob(node.left.left)

            if node.right != None:
                val_root_1 += recur_rob(node.right.left) + recur_rob(node.right.right)
            
            val_root_2 = recur_rob(node.left) + recur_rob(node.right)
            
            memory[node] = max(val_root_2, val_root_1)
            return memory[node]

        return recur_rob(root)






    
        
        
# @lc code=end


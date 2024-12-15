#
# @lc app=leetcode.cn id=968 lang=python3
#
# [968] 监控二叉树
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # 用到的贪心算法：最少的摄像头那必定是在叶子节点的父节点上放可以达到最小的摄像头数
    # 后序遍历
    # 还需要判断最后根节点有没有被覆盖上
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        # 0 表示没有被覆盖
        # 1 表示本身存在摄像头
        # 2 已经被覆盖
        res = 0
        def traversal(cur: TreeNode) -> int:
            # 空节点算作是已经被覆盖 因为要在叶子节点的父节点放摄像头
            # 引入外部变量？？？
            nonlocal res
            if cur == None:
                return 2
            
            left = traversal(cur.left)
            right = traversal(cur.right)
            
            if left == 2 and right == 2:
                # 两个子节点都已经被覆盖, 父节点是没有被覆盖的
                return 0
            
            # 两个子节点有一个没有被覆盖，那肯定都父节点就需要放摄像头 
            if left == 0 or right == 0:
                res += 1
                return 1
            
            # 两个子节点有一个有摄像头
            if left == 1 or right == 1:
                return 2
            return -1
        
        if traversal(root) == 0:
            res += 1
        return res
            
           

            
            
    
        
# @lc code=end


#
# @lc app=leetcode.cn id=3248 lang=python3
#
# [3248] 矩阵中的蛇
#

# @lc code=start
class Solution:
    def finalPositionOfSnake(self, n: int, commands: List[str]) -> int:
        col = 0
        row = 0
        for command in commands:
            if command[0] == "U":
                col -= 1
            if command[0] == "D":
                col += 1
            if command[0] == "R":
                row += 1
            if command[0] == "L":
                row -= 1
        return col * n + row


            


        
# @lc code=end


#
# @lc app=leetcode.cn id=52 lang=python3
#
# [52] N 皇后 II
#

# @lc code=start
class Solution:
    def totalNQueens(self, n: int) -> int:
        cols = [False] * n
        arr1 = [False] * (2 * n - 1)
        arr2 = [False] * (2 * n - 1)
        self.res = 0
        board = [['.' for _ in range(n)] for _ in range(n)]
        def backtrack(row: int):
            if row == n:
                self.res += 1
                return
            
            for col in range(n):
                if cols[col] or arr1[row + col] or arr2[row - col + n - 1]:
                    continue
                
                arr1[row + col] = True
                arr2[row - col + n - 1] = True
                cols[col] = True
                board[row][col] = 'Q'
                backtrack(row + 1)
                arr1[row + col] = False
                arr2[row - col + n - 1] = False
                cols[col] = False
                board[row][col] = '.'
        backtrack(0)
        return self.res

            
                

        
# @lc code=end


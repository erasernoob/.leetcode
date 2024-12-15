#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N 皇后
#

# @lc code=start
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        # 主对角线和副对角线
        arr1 = [False] * (2 * n - 1) 
        arr2 = [False] * (2 * n - 1) 
        cols = [False] * (n) 
        board = [['.' for _ in range(n)] for _ in range(n)]
        def backtrack(r: int):
            if r == n:
                res.append([''.join(board[i]) for i in range(len(board))])
                return
            
            for col in range(n):
                if arr1[col + r] or arr2[r - col + n - 1] or cols[col]:
                    continue
                board[r][col] = 'Q'
                arr1[r + col] = True
                arr2[r - col + n - 1] = True
                cols[col] = True
                backtrack(r + 1)
                board[r][col] = '.'
                cols[col] = False
                arr1[r + col] = False
                arr2[r - col + n - 1] = False
        backtrack(0)
        return res

                    
     
            




            
                    




        
# @lc code=end


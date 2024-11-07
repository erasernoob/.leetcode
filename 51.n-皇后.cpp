/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<string> board;
    vector<vector<string>> res;
    vector<bool> arr1;
    vector<bool> arr2;
    vector<bool> cols;
    vector<vector<string>> solveNQueens(int n) {
        arr1.resize(2 * n - 1, false); // r + c
        arr2.resize(2 * n - 1, false); // r - c 's index should consider the edge case is the (n - 1)
        cols.resize(n, false); // 
        board.resize(n, string(n, '.'));
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int row) {
        if(row == n) {
            res.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(!arr1[row + c] && !arr2[row - c + n - 1] && !cols[c] && board[row][c] == '.') {
                arr1[row + c] = arr2[row - c + n - 1] = cols[c] = true;
                board[row][c] = 'Q';
                backtrack(n, row + 1);
                board[row][c] = '.';
                arr1[row + c] = arr2[row - c + n - 1] = cols[c] = false;
            }
        }

    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    // 找到一行的结果的过程相当于就是之前的排列组合n皇后问题，同时这是一个矩阵，每一行每一列也有约束，
    // 所以需要在一层“n皇后” 下面再套一层“n皇后”，从而是二维递归

    // 使用两个二维数组分别记录n行列，是否出现过该数字
    vector<vector<bool>> rows;
    vector<vector<bool>> cols;
    vector<vector<bool>> box;
    void solveSudoku(vector<vector<char>>& board) {
        // 初始哈希表
        rows.resize(board[0].size(), vector<bool>(10, false));
        cols.resize(board[0].size(), vector<bool>(10, false)); 
        box.resize(board[0].size(), vector<bool>(10, false)); 

        int n = board[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    box[(i / 3) * 3 + (j / 3)][num] = true; // 更新子块状态
                }
            }
        }
        backtrack(board, board[0].size());
    }

    bool isValid(vector<vector<char>>& board, int row, int col, int i) {
        char obj = i + '0';
        // 检查九宫格内的是否存在
        for(int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++) {
            for(int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++) {
                if(board[i][j] == obj) return false;
            }
        }
        return true;
    }


    bool backtrack(vector<vector<char>>& board, int n) {
        for(int row= 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(board[row][col] == '.') {
                for(int i = 1; i <= 9; i++) {
                    if(!rows[row][i] && !cols[col][i] && !box[(row / 3) * 3 + (col / 3) * 3 ][i]) {
                        rows[row][i] = cols[col][i]  = box[(row / 3) * 3 + (col / 3) * 3 ][i] = true;
                        board[row][col] = i + '0';
                        if(backtrack(board, n)) return true;
                        board[row][col] = '.';
                        rows[row][i] = cols[col][i]  = box[(row / 3) * 3 + (col / 3) * 3 ][i] = false;
                    }
                }
                return false;
                }
            }
        }
        return true;

    }

};
// @lc code=end


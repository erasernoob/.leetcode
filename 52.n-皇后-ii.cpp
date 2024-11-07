/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
public:
    int res = 0;
    vector<bool> arr1, arr2, cols; 
    int totalNQueens(int n) {
        // 用哈希表分别检查 r+c & r-c 是否出现过
        // 因为45`，r-c的值就是相等的
        // 135`时上r+c=n
        cols.resize(n, false);
        arr1.resize(2 * n, false);
        // 在左上角处会出现 -(n-1) 所以需要加上保护值 n-1
        arr2.resize(2 * n, false);
        backtrack(n, 0);
        return res;
    }

    void backtrack(int n, int row) {
        if(row == n) {
            res++;
            return;
        }

        for(int col = 0; col < n; col++) {
            if(!cols[col] && !arr1[row + col] && !arr2[row - col + n]) {
                arr2[row - col + n] = true;
                arr1[row + col] = true;
                cols[col] = true;
                backtrack(n, row + 1);
                cols[col] = false;
                arr1[row + col] = false;
                arr2[row - col + n] = false;
            }
        }
    }
};
// @lc code=end


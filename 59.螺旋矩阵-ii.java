/*
 * @lc app=leetcode.cn id=59 lang=java
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
    // BREAKING: the loop constant varible principle(Never change in the loop)
    // choose to left affect , while the right not affect
    public int[][] generateMatrix(int n) {
        // use the threshold value
        int[][] mat = new int[n][n];
        int cnt = 1;
        int target = n * n;
        // the constraint value
        int l = 0, r = n-1, t = 0, b = n-1; // when they move to opposite their final value
        while(cnt <= target){
            for(int i = l; i <= r; i++) mat[t][i] = cnt++; 
            // top shrink sub
            t++;
            for(int i = t; i <= b; i++) mat[i][r] = cnt++; 
            r--;
            for(int i = r; i >= l; i--) mat[b][i] = cnt++; 
            b--;
            for(int i = b; i >= t; i--) mat[i][l] = cnt++; 
            l++;
        } 

        return mat;
    }
}
// @lc code=end


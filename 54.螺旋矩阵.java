/*
 * @lc app=leetcode.cn id=54 lang=java
 *
 * [54] 螺旋矩阵
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if(matrix == null) {
            return new ArrayList<Integer>();
        }
        int l = 0, r = matrix[0].length-1, t = 0, b = matrix.length-1, count = 0;
        List<Integer> ret = new ArrayList<>();

        // [i, j]
        while(true) {
            // l -> right
            for(int i = l;i <= r; i++) ret.add(matrix[t][i]);
            // top++
            if(++t > b) break; // quit condition
            for(int i = t; i <= b; i++) ret.add(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; i--) ret.add(matrix[b][i]);
            if(--b < t) break;
            for(int i = b; i >= t; i--) ret.add(matrix[i][l]);
            if(++l > r) break;
        }
        return ret;
    }

}
// @lc code=end











































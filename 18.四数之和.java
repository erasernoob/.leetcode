/*
 * @lc app=leetcode.cn id=18 lang=java
 *
 * [18] 四数之和
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        Scanner scanner = new Scanner(System.in);
        char tmp = scanner.next;
        StringBuilder builder = new StringBuilder();
        while(tmp != '\n') {
            if(tmp >= '1' && tmp <= '9') {
                builder.append("number");
            }
            else {
                builder.append(tmp);
            }
            tmp = scanner.next();
        }
        return builder.toString();
    }
}
// @lc code=end


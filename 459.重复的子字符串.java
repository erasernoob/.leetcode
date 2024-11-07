/*
 * @lc app=leetcode.cn id=459 lang=java
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        return true;
    }

    private int[] getNextArr(String s) {
        char[] t = s.toCharArray();
        int[] next = new int[t.length];
        // 初始化两指针
        int j = -1;
        next[0] = j;

        for (int i = 1; i < arr.length; i++) {
            if(t[i] == t[j + 1]) {
                j++;
            }
            next[i] = j;
            while(j >= 0 && t[i] != t[j + 1]) {
                j = next[j];
            }
        }
    }
}
// @lc code=end


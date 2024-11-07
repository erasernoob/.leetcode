/*
 * @lc app=leetcode.cn id=541 lang=java
 *
 * [541] 反转字符串 II
 */

// @lc code=start
class Solution {
    public String reverseStr(String s, int k) {
        char[] t = s.toCharArray();
        for (int i = 0; i < t.length; i += 2*k) {
            if(i + k < t.length) {
                reverseString(t, i, i + k-1);

            } else {
                reverseString(t, i, t.length - 1);
            }
        }
        return String.valueOf(t);
    }
    public void reverseString(char[] s, int start , int end) {
        while(start < end) {
            // s[start] ^= s[end];
            // s[end] ^= s[start];
            // s[start] ^= s[end];
            char tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            start++;
            end--;
        }
    }
}
// @lc code=end


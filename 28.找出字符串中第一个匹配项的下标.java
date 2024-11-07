/*
 * @lc app=leetcode.cn id=28 lang=java
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
    public int strStr(String haystack, String needle) {

    }

    public int[] getNext(String s) {
        int[] next = new int[s.length()];
        // next数组正常不减一的版本
        int j = 0; next[0] = j; 

        for (int i = 1; i < next.length; i++) {
            while(j > 0 && s.charAt(i) != s.charAt(j)) {
                j = next[j-1];
            }
            if(s.charAt(i) == s.charAt(j)) {
                j++;
            }
            next[j] = j;
        }
    }

    
}
// @lc code=end


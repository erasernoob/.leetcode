/*
 * @lc app=leetcode.cn id=383 lang=java
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        char[] m = magazine.toCharArray();
        char[] r = ransomNote.toCharArray();

        int[] res = new int[26];
        for (int i = 0; i < m.length; i++) {
            res[m[i] - 'a']++;
        }
        for (int i = 0; i < r.length; i++) {
            res[r[i] - 'a']--;
        }

        for (int i = 0; i < res.length; i++) {
            if(res[i] < 0) return false;
        }
        return true;
    }
}
// @lc code=end


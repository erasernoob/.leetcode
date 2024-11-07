/*
 * @lc app=leetcode.cn id=242 lang=java
 *
 * [242] 有效的字母异位词
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public boolean isAnagram(String s, String t) {
        char[] arr1 = s.toCharArray();
        char[] arr2 = t.toCharArray();
        if(s.length() != t.length()) {
            return false;
        }
        int[] arr = new int[1000];
        int[] tmp = new int[1000];
        for (int i = 0; i < arr2.length; i++) {
            arr[arr2[i] - 'a']++;
        } 
        for (int i = 0; i < arr1.length; i++) {
            tmp[arr1[i] - 'a']++;
        }
        return Arrays.equals(arr,tmp);

    }
}
// @lc code=end


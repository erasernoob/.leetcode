/**
 * @lc app=leetcode.cn id=151 lang=java
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
    public String reverseWords(String s) {
        // 1. remove the extra space
        // 2. reverse the whole string
        // 3. reverse the word

        // I.erase the inital space
        int start = 0, end = s.length()-1;
        while(s.charAt(start) == ' ') start++;
        while(s.charAt(end) == ' ') end--;
        s = s.substring(start, end + 1);
        StringBuilder t = removeSpace(s);

        s = reverseString(t.toString());

        return reverseWord(s);

    }

    private String reverseWord(String s) {
        char[] t = s.toCharArray();
        int slow = 0;
        int end = t.length - 1;
        for (int i = 0; i < t.length; i++) {
            if(t[end] != ' ') {
                end--;
            }
            if(t[i] == ' ') {
                reverseString(t, slow, i-1);
                slow = i + 1;
            }
        } 
        reverseString(t, end + 1, t.length - 1);
        return String.valueOf(t);
    }

    private void reverseString(char[] t, int l, int r)  {
        while(l < r) {
            t[l] ^= t[r];
            t[r] ^= t[l];
            t[l] ^= t[r];
            l++; r--;
        }
    }

    private String reverseString(String s) {
        int l = 0,  r = s.length() - 1;
        char[] t = s.toCharArray(); 
        while(l < r) {
            t[l] ^= t[r];
            t[r] ^= t[l];
            t[l] ^= t[r];
            l++; r--;
        }
        return String.valueOf(t);
    }

    private StringBuilder removeSpace(String s) {
        StringBuilder t = new StringBuilder();
        int start = 1, end = s.length()-1;
        t.append(s.charAt(0));
        while(start <= end) {
            if(s.charAt(start) == ' ' && s.charAt(start - 1) == ' ') {
                start++;
            } else {
                t.append(s.charAt(start));
                start++;
            }
        }
        return t;

    }
}
// @lc code=end


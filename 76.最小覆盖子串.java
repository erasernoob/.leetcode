/*
 * @lc app=leetcode.cn id=76 lang=java
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
    // BREAKING: when the left move and rigt stop
    public String minWindow(String s, String t) {
        int l = 0; int r = 0;
        int[] cnts = new int[128];
        int[] cntt = new int[128];
        char[] S = s.toCharArray();
        char[] T = t.toCharArray();
        // initialize the cntT arr
        for(int i = 0; i < T.length; i++) {
            cntt[T[i]]++;
        }

        int ansL = -1; int ansR = S.length;
        while(r < S.length) {
            // record the right char
            cnts[S[r]]++; 
            while(isCovered(cnts, cntt)) {
                if(ansR - ansL > r - l) {
                    ansL = l;
                    ansR = r;
                }
                cnts[S[l++]]--;
            }
            r++;
        }
        if(ansL < 0) return "";
        else return s.substring(ansL, ansR + 1);
    }


    boolean isCovered(int[] cnts, int[] cntt) {
        for(int i = 'A'; i <= 'Z'; i++) {
            if(cnts[i] < cntt[i]) {
                return false;
            }
        }

        for(int i = 'a'; i <= 'z'; i++) {
            if(cnts[i] < cntt[i]) {
                return false;
            }
        }
        return true;
    }
}
// @lc code=end


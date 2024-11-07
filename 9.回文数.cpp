/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int cur = 0, t = x;
        while(x) {
            cur = cur * 10 + x % 10;
            x /= 10;
        }
        return cur == t;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=202 lang=java
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {

    public int getSqureSum(int n) {
        // execute one loop
        int sum = 0;
        while(n != 0) {
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
    }

    public boolean isHappy(int n) {
        // infinite we can use the fast and slow index
        int fast = n, slow = n;
        fast = getSqureSum(fast);
        fast = getSqureSum(fast);
        slow = getSqureSum(slow);
        while(fast != slow) {
            fast = getSqureSum(fast);
            fast = getSqureSum(fast);
            slow = getSqureSum(slow);   
        }
        return fast == 1;
    }
}
// @lc code=end


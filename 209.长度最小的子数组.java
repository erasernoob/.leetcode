/*
 * @lc app=leetcode.cn id=209 lang=java
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
    // slide window
    // when the left update and the right stop
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0, r = 0;
        int minLength = 1000000;
        int sum = 0;

        for(; r < nums.length; r++) {
            // udpate the state
            sum += nums[r];
            while(sum >= target) { // left will go move condition
                int length = r - l  + 1; // current length 
                minLength = minLength < length ? minLength : length;
                sum -= nums[l++];
            }

        }
        if(minLength == 1000000) return 0;
        return minLength;
    }
}
// @lc code=end


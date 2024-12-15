/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // 滑动窗口？
        int left = 0;
        int sum = 0, res = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= target) {
                int length = i - left + 1;
                res = res > length ? length : res;
                sum -= nums[left];
                left++;
            } 
        }
        return res == INT_MAX ? 0 : res;
    }
};
// @lc code=end


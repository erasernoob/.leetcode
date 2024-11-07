/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // greedy point -> when the result get negative drop
        int res = INT_MIN;
        int cur = 0;
        for(int i = 0; i < nums.size(); i++) {
            cur += nums[i];
            res = res > cur ? res : cur;

            if(cur < 0) cur = 0;
        }
        return res;
    }
};
// @lc code=end


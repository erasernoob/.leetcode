/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int res = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if(sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            res = res > sum ? res : sum;
            
        }
        return res;
    }
};
// @lc code=end


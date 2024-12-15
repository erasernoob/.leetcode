/*
 * @lc app=leetcode.cn id=3255 lang=cpp
 *
 * [3255] 长度为 K 的子数组的能量值 II
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        // 滑动窗口
        int left = 0;
        vector<int> res(nums.size() - k + 1, -1);
        if(res.size() == 1) res[0] = nums[0]; 
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] - nums[i-1] != 1) {
                left = i; // 从当前位置重新开始
                continue;
            }

            if(i - left + 1 == k) {
                res[i - k + 1] = nums[i];
                left++;
            }
        }
        return res;
    }
};
// @lc code=end


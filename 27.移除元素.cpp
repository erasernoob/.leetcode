/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int construct = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[construct++] = nums[i];
            }
        }
        return construct;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=3254 lang=cpp
 *
 * [3254] 长度为 K 的子数组的能量值 I
 */

// @lc code=start
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i <= nums.size() - k; i++) {
            int max = nums[i + k - 1];
            for(int j = i + k - 1; j > i; j--) {
                if(nums[j] - nums[j-1] != 1) {
                    max = -1;
                }
            }
            res.push_back(max);
        }
        return res;
    }
};
// @lc code=end


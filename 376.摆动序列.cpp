/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {

public:
// no more flag to specify the status of the code it is definitely un-elegant!!!
    int wiggleMaxLength(vector<int>& nums) {
        int pre_diff = 0, cur_diff = 0;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            cur_diff = nums[i] - nums[i - 1];
            if(pre_diff <= 0 && cur_diff > 0 || pre_diff >= 0 && cur_diff < 0) {
                cnt++;
                pre_diff = cur_diff;
            }
        }
        return cnt;
    }
};
// @lc code=end


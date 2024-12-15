/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int left = 0, right = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i >= left && i <= right) {
                int tmp = i + nums[i];
                if(tmp >= right) right = tmp;
            }
            if(right >= nums.size() - 1)  return true;
        }
        return false;
    }
};
// @lc code=end


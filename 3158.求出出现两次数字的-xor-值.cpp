/*
 * @lc app=leetcode.cn id=3158 lang=cpp
 *
 * [3158] 求出出现两次数字的 XOR 值
 */

// @lc code=start
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> location(51, 0);
        vector<int> res(51, 0);
        int cnt = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            location[nums[i]]++;
            if(location[nums[i]] == 2) {
                res[cnt++] = nums[i];
            }
        }
        int ret = 0;
        for (size_t i = 0; i < cnt; i++) {
            if(res[i] != 0) {
                ret ^= res[i];
            }
        }
        return ret;
    }
};
// @lc code=end


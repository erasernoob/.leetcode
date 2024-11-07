/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    // 子集问题就是选择问题 横向循环选择了一个数，之后就不能再选了，纵向递归，只能在没有选过的剩下的自己子集中挑选
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int index) {
        if(index <= nums.size()) {
            res.push_back(path);
        }

        for(int i = index; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end


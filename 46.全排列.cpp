/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:

    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums, 0);
        return res;
    }
    void backtrack(vector<int>& nums, int startIndex) {
        if(path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(i);
            backtrack(nums, i + 1);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end


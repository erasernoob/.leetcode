/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<bool> used; 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        used.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }

    void backtrack(vector<int>& nums) {
        if(path.size() == nums.size()) {
            res.push_back(path);
        }

        unordered_set<int> set;
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] || set.find(nums[i]) != set.end()) continue;
            set.insert(nums[i]);
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums);
            used[i] = false;
            path.pop_back();
        }
    }
};
// @lc code=end


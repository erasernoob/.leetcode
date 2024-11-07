/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int index) {
        if(path.size() >= 2) {
            res.push_back(path);
        }

        unordered_set<int> set;
        for(int i = index; i < nums.size(); i++) {
            if(i > index && set.find(nums[i]) != set.end()) continue;
            set.insert(nums[i]);
            if(!path.empty() && path[path.size() - 1] <= nums[i] || path.empty()) {
                path.push_back(nums[i]);
                backtrack(nums, i + 1);
                path.pop_back();
            }
       }
    }
};
// @lc code=end


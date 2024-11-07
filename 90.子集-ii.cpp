/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int startIndex) {
        res.push_back(path);

        for(int i = startIndex; i < nums.size(); i++) {
            if(i > startIndex && nums[i] == nums[i - 1]){
                continue;
            }
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end


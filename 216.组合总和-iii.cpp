/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtrack(k, n, 0, 1);

        return res;
    }

    void backtrack(int nums, int target, int sum, int startIndex) {
        if(sum > target) {
            return;
        }
        if(path.size() == nums && sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i <= 9 && sum + i <= target; i++) {
            path.push_back(i);
            backtrack(nums, target, sum + i, i + 1);
            path.pop_back();
        }
        
    }

    
};
// @lc code=end


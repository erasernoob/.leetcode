/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int targetSum, int sum, int index) {
        if(sum > targetSum) return;
        if(sum == targetSum) {
            res.push_back(cur);
            return;
        }

        for(int i = index; i < candidates.size() && candidates[i] + sum <= targetSum; i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, targetSum, sum + candidates[i], i);
            cur.pop_back();
        }

    }

};
// @lc code=end


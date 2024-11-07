/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> cur;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 强调一下，数组去重的话，需要排序！！！！
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int startIndex) {
        if(target < 0) {
            return;
        }
        if(target == 0) {
            res.push_back(cur);
            return;
        }

        for(int i = startIndex; i < candidates.size(); i++) {
            if(i > startIndex && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1); // i 可以重复用数组里的元素，但是在上面就不行了 
            cur.pop_back();
        }
    }
};
// @lc code=end


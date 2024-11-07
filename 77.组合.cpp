/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        // the first problem to enter into the backatrace 
        backtrace(n, k, 1);
        return result;
    }

    void backtrace(int n, int k, int starerIndex) {
        if(path.size() == k) {
            result.push_back(path);
            return;
        }

        for(int i = starerIndex; i <= n - (k - path.size()) + 1; i++) {
            path.push_back(i);
            backtrace(n, k, i + 1);
            path.pop_back();
        }
    }
};
// @lc code=end


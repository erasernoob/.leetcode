/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = INT_MIN;
        int cur = 0;
        for(int i = 1; i < prices.size(); i++) {
            cur += prices[i] - prices[i - 1];
            if(cur > max) max = cur;

            if(cur < 0) cur = 0;
        }
        return max;
    }
};
// @lc code=end


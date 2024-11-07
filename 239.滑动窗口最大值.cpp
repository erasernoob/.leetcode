/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public: 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 实现单调队列
        vector<int> res;
        deque<int> q;
        for (size_t i = 0; i < k; i++) {
            while(!q.empty() && nums[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[i]);
        }
        res.push_back(q.front());
        for(int i = k; i < nums.size(); i++) {
            if(nums[i - k] == q.front()) {
                q.pop_front();
            }
            while(!q.empty() && nums[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[i]);
            res.push_back(q.front());
        }
        return res;
    }
};
// @lc code=end


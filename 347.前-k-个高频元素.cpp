/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    class mycomparision {
        public:
            bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
                return lhs.second > rhs.second;
            }
        };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (size_t i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int, int>>, mycomparision> queue;

        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
            queue.push(*it);
            if(queue.size() > k) {
                queue.pop();
            }
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; i--) {
            res[i] = queue.top().first;
            queue.pop();
        }
        return res;
    }
};
// @lc code=end


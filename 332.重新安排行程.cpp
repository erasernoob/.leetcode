/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @lc code=start
class Solution {
public:
    // 记录映射关系的map
    // 记录了当前航线中，两个机场之间是否已经飞过了，避免重复死循环
    unordered_map<string, map<string, int>> targets;
    vector<string> result;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // 初始化映射关系map
        for(auto vec : tickets) {
            targets[vec[0]][vec[1]]++; // 记录有关系的两个机场，数量加1,之后方便判断去重剪枝
        }
        result.push_back("JFK");
        backtrack(tickets.size());
        return result;
    }
    bool backtrack(int flightNums) {
        // 当目标机场的数量达到了航班的数量-1 返回true 返回目标结果数组
        if(result.size() == flightNums + 1) {
            return true;
        } 

        for(pair<const string, int>& obj : targets[result[result.size() - 1]]) {
            if(obj.second > 0) {
                obj.second--;
                result.push_back(obj.first);
                if(backtrack(flightNums)) return true;
                result.pop_back();
                obj.second++;
            }
        }
        return false;
    }
};
// @lc code=end


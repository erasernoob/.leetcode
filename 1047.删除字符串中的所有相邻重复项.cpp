/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> t;
        t.push(s[s.size() - 1]);
        for (int i = s.size() - 2; i >= 0; i--) {
            if(!t.empty() && t.top() == s[i]) {
                t.pop();
                continue;
            };
            t.push(s[i]);
        }
        while(!t.empty()) {
            char tmp = t.top();
            t.pop();
            res.push_back(tmp);
        }
        return res;
    }
};
// @lc code=end


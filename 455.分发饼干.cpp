/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1, cnt = 0;
        for(int i = g.size() - 1; i > -1; i--) {
            if(s[index] >= g[i] && index >= 0) {
                cnt++;
                index--;
            }
            
        }
        return cnt;
    }
};
// @lc code=end


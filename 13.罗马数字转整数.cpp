/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        std::map<char, int>  m;
        m['I'] =  1;
        m['V'] =  5;
        m['X'] =  10;
        m['L'] =  50;
        m['C'] =  100;
        m['D'] =  500;
        m['M'] =  1000;

        int value = 0;
        int pre = 1001;
        int res = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            char cur = s[i];
            value =  m[cur];
            if(value > pre) {
                res -= value;
            } else {
                res += value;
            }
            pre = value;
        }
        return res;
    }
};
// @lc code=end


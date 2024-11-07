/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (size_t i = 0; i < s.size(); i++) {
            if(t.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']'))  {
                
                return false;
            }
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
            } else {
                char res = t.top();
                t.pop();
                if(res == '(' && s[i] == ')' || res == '{' && s[i] == '}' || s[i] == ']' && res == '[') {
                    continue;;
                } else {
                    return false;
                }
            }
        }
        return t.empty();
        



    }
};
// @lc code=end


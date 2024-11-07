/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    map<char, string> digitMap;
    vector<string> letterCombinations(string digits) {
        digitMap['2'] = "abc";
        digitMap['3'] = "def";
        digitMap['4'] = "ghi";
        digitMap['5'] = "jkl";
        digitMap['6'] = "mno";
        digitMap['7'] = "pqrs";
        digitMap['8'] = "tuv";
        digitMap['9'] = "wxyz";
        string cur = "";
        if(digits.empty()) return res;
        backtrack(digits, 0, cur);
        return res;
    }

    void backtrack(string digits, int index, string cur) {
        if(index == digits.size()) {
            res.push_back(cur);
            return;
        }

        string str = digitMap[digits[index]];
        for(int i = 0; i < str.size(); i++) {
            backtrack(digits, index + 1, cur + str[i]);
        }
    }
};
// @lc code=end


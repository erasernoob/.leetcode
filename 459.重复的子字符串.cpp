/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int next[s.size()];
        getNext(&next[0], s);
        int length = next[s.size() - 1];
        return (s.size() % (s.size() - length) == 0) && (length != 0);
    }
    void getNext(int *next, string s) {
        int j = 0; next[0] = 0;
        for (size_t i = 1; i < s.size(); i++) {
            while(j > 0 && s[j] != s[i]) {
                j = next[j - 1];
            }
            if(s[j] == s[i]) {
                j++;
            }
            next[i] = j;
        }
    }

};
// @lc code=end


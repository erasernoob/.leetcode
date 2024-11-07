/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> isPalindrome;
    vector<vector<string>> partition(string s) {
        // 动态规划优化处理回文逻辑版本
        palindrome(s);
        backtrack(s,0);
        return res;
    }

    void backtrack(string s, int startIndex) {
        if(startIndex >= s.size()) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            if(isPalindrome[startIndex][i]) {
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
                backtrack(s, i + 1);
                path.pop_back();
            }
       }
    }

    void palindrome(string s) {
        // use the dp thinking solve the 
        // 1. s[n-1] = s[0]
        // 2. s[1:n-1] is palindrome
        // initialize the isPalindrome vector
        isPalindrome.resize(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; i--) {
            for(int j = i; j <= s.size(); j++) {
                if(i == j) isPalindrome[i][j] = true;
                else if ( j - i == 1) isPalindrome[i][j] = (s[i] == s[j]);
                else {
                    isPalindrome[i][j] == (s[i] == s[j]) && isPalindrome[i+1][j-1];
                }
            }
        }
    }

};
// @lc code=end


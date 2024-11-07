/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        // 分割就是组合的一种，在这里使用数组本身进行分割，通过添加句点的方式
        backtrack(s, 0, "", 0);
        return res;
    }

    void backtrack(string s, int pointNums, string path, int startIndex) {
        // 三个句点是完成切割并返回
        if(startIndex >= s.size()) {
            return;
        }
        if(pointNums == 3 && isValid(s, startIndex, s.size() - 1)) { 
            res.push_back(path + s.substr(startIndex, s.size() - startIndex));
            return;
        }

        for(int i = startIndex; i < s.size(); i++) {
            // 切割好的字符串
            if(isValid(s, startIndex, i)) {
                backtrack(s, pointNums + 1, path + s.substr(startIndex, i - startIndex + 1) + '.', i + 1);
            }
        }
    }


    bool isValid(string s, int begin, int end) {
        if(end - begin >= 3 || s[0] == '0' && begin != end) return false;
        int res = stoi(s.substr(begin, end - begin + 1));
        return res <= 255 && res >= 0;
    }
};
// @lc code=end


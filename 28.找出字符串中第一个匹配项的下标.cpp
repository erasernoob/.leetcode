/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        int next[needle.size()];
        getNext(&next[0], needle); // get the next arr for the haystack
        int j =  0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]) {
                j++;
            }
            if(j == needle.size()) {
                return (i - j + 1);
            } 
        }
        return -1;
        
    }

    void getNext(int *next, string str) {
        // initial the arr and the double index
        int j = 0; next[0] = j;
        // handle the two different situations
        // i as the back index???????
        for (int i = 1; i < str.size(); i++) {
            while(j > 0 && str[j] != str[i]) {
                j = next[j - 1]; // handle the different 
            }
            if(str[j] == str[i]) {
                j++;
            }
            next[i] = j;
        }
    }
};
// @lc code=end


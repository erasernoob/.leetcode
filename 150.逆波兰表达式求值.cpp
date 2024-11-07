/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        int ret = 0;
        for(string c : tokens) {
            // 正数
            if(c.size() > 1 || c[0] >= '0' && c[0] <= '9') {
                int num = stoi(c);
                nums.push(num);
            } else if(c.size() > 1 && c[0] == '-') {
                int num = stoi(c);
                nums.push(num);
                
            } else if (c[0] == '*') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                a = a * b;
                nums.push(a);
            } else if(c[0] == '+') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                a = a + b;
                nums.push(a);
            } else if (c[0] == '/') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                a = b / a;
                nums.push(a);
            }
            else if (c[0] == '-') {
                int a = nums.top();
                nums.pop();
                int b = nums.top();
                nums.pop();
                a = b - a;
                nums.push(a);
            }
        }
        return nums.top();
        return 1;
    }

    int convertNum(string s) {
        int ret = 0, cnt = 1;
        if(s[0] == '-') {
            for ( int i = s.size() - 1; i >= 1; i--) {
                int tmp = s[i] - 48;
                ret += cnt * tmp;
                cnt *= 10;
            }
            ret = (-1) * ret;
        } else {
        for ( int i = s.size() - 1; i >= 0; i--) {
            int tmp = s[i] - 48;
            ret += cnt * tmp;
            cnt *= 10;
        }
        }
        return ret;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=3200 lang=cpp
 *
 * [3200] 三角形的最大高度
 */

// @lc code=start
class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        // stimulate 
        int a = maxHeight(red, blue);
        int b = maxHeight(blue, red);
        cout << "a:" << a  << " b:" << b;
        return max(a, b);
    }

    int maxHeight(int first, int second) {
        // start with the red ball
        // put the red first then blue comes next
        int flag = 1; // as the sign to switch between the even and odd
        int cnt = 1;
        while(true) {
            // red one
            if(flag) {
                first -= cnt;
                if(first < 0) {
                   // not enough to put this line 
                   break;
                }
            } else {
                second -= cnt;
                if(second < 0) {
                    break;
                }
            }
            cnt++;
            flag = !flag;
        } 
        return cnt - 1;
    }

};
// @lc code=end


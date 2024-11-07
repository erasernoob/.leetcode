/*
 * @lc app=leetcode.cn id=3222 lang=cpp
 *
 * [3222] 求出硬币游戏的赢家
 */

// @lc code=staclass Solution {
public:
    string losingPlayer(int x, int y) {
        int flag = 0;  // 0 for alice 1 for bob
        // the winner is the ~flag
        while(true) {
            if(x < 1) break;
            if(y < 4) break;
            x--;
            y -= 4;
            flag = !flag;
        }
        return flag == 1 ? "Alice" : "Bob";
    }
};
// @lc code=end


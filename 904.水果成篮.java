/*
 * @lc app=leetcode.cn id=904 lang=java
 *
 * [904] 水果成篮
 */

// @lc code=start
class Solution {
    /**
     * slide window top problem : Definite have a hashtable or arr to restore current situation
     * @param fruits
     * @return
     */
    public int totalFruit(int[] fruits) {
        int left = 0; int right = 0;
        // right is the end point left is the start pointer
        int cates = 0; // represents the cate of the numbers (difference)
        // main UnderStanding for this right goes if the cates > 2 then the left pointer++
        int[] record = new int[fruits.length + 1]; // record the numbers apperance times
        int ans = 0;
        while(right < fruits.length) {
            // if the right pointers encounter a new number
            if(record[fruits[right++]]++ == 0) cates++;

            while(cates > 2) {
                if(record[fruits[left++]]-- == 1) cates--;
            } 
            ans = Math.max(right-left, ans);
        }
        return ans;
    }
}
// @lc code=end


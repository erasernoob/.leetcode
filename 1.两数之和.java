/*
 * @lc app=leetcode.cn id=1 lang=java
 *
 * [1] 两数之和
 */

// @lc code=start

import java.util.HashMap;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] ret = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int res = target - nums[i];
            if(map.containsKey(res)) {
                ret[1] = i;
                ret[0] =  map.get(res);
            } else {
                map.put(nums[i], i);
            }
        }
        if(ret[0] == ret[1]) return new int[0];
        return ret;
        
    }
}
// @lc code=end


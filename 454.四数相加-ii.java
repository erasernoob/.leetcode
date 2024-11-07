/*
 * @lc app=leetcode.cn id=454 lang=java
 *
 * [454] 四数相加 II
 */

// @lc code=start

import java.util.HashMap;

class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        // typically use the hashMap problem
        // key for nums's value value for nums' index
        // first record the 1 and 2 nums' Sum's appear's times
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums4.length; i++) {
            for (int j = 0; j < nums3.length; j++) {
                int sum =  nums3[j] + nums4[i];
                map.put(sum, map.getOrDefault(sum, 0) + 1);
            }
        }
        int cnt = 0;
        for (int i = 0; i < nums1.length; i++) {
            for (int j = 0; j < nums2.length; j++) {

            int sum =  -(nums1[i] + nums2[j]);
            if(map.containsKey(sum)){
                cnt += map.get(sum);
            }
            }
        }
        return cnt;
    }
}
// @lc code=end


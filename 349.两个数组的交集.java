/*
 * @lc app=leetcode.cn id=349 lang=java
 *
 * [349] 两个数组的交集
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    /**
     * @param nums1
     * @param nums2
     * @return
     */
    public int[] intersection(int[] nums1, int[] nums2) {
        // use the times that these numbers appears 
        Map<Integer, Integer> map = new HashMap<>(); 
        List<Integer> arr = new ArrayList<>();
        for (int i : nums2) {
            // how to increment the Java's hasmap's value by this
            map.put(i ,1); // record the appear's time
        }
        for (int i : nums1) {
            map.put(i, map.getOrDefault(i, 0)-1); // record the appear's time
            if(map.get(i) == 0) {
                arr.add(i);
            }
        }
        return arr.stream().mapToInt(i -> i).toArray();

    }
    
}
// @lc code=end


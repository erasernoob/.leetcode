/*
 * @lc app=leetcode.cn id=15 lang=java
 *
 * [15] 三数之和
 */

// @lc code=start

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

class Solution {
    // see the a + b + c as the specific number, the three number every one is independent  
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res =  new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if(nums[0] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i + 1, right = nums.length - 1;
            while(left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else  {
                    List<Integer> r = new ArrayList<Integer>();
                    r.add(nums[left]);
                    r.add(nums[i]);
                    r.add(nums[right]);
                    res.add(r);
                    
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                }
            }
        }
        return res;
    }
}
// @lc code=end


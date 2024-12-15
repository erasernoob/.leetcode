#
# @lc app=leetcode.cn id=1005 lang=python3
#
# [1005] K 次取反后最大化的数组和
#

# @lc code=start
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        # sort 
        # all negative 1. odd and even change from the smallest 
        # all positive 1. odd -> change from the smallest 2. even -> return 
        # n & p : start from the smallest and change to the all positive situatin
        nums = sorted(nums)
        sum = 0
        print(nums)
        for i in range(len(nums)):
            if nums[i] < 0 and k > 0:
                nums[i] = abs(nums[i])
                k -= 1
        if k >= 1:
            nums = sorted(nums)
            nums[0] = -nums[0]
        for i in nums:
            sum += i
        return sum
            
    

        
# @lc code=end


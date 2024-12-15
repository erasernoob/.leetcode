#
# @lc app=leetcode.cn id=134 lang=python3
#
# [134] 加油站
#

# @lc code=start
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        for i in range(len(gas)):
            oil = gas[i]
            j = i
            while(oil - cost[j] >= 0):
                oil -= cost[j]
                oil += gas[(j + 1) % len(gas)]
                j = (j + 1) % len(gas)
                if j == i: return i
        return -1
        
# @lc code=end
















































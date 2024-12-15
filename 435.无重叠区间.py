#
# @lc app=leetcode.cn id=435 lang=python3
#
# [435] 无重叠区间
#

# @lc code=start
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # 按照左边进行排序
        intervals.sort(key=lambda x : (x[0], x[1]))
        cur = intervals[0][1]
        cnt = 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < cur:
                cnt += 1
                cur = min(intervals[i][1], cur)
            else:
                cur = intervals[i][1]
        return cnt
                
            
        
        





            
        
# @lc code=end


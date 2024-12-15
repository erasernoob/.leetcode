#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#

# @lc code=start
# class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        # 两个维度的题目 
        # 按左边排序？ => 
        intervals.sort(key=lambda x : (x[0], x[1]))
        res = []
        res.append(intervals[0])
        for i in range(1, len(intervals)):
            if intervals[i][0] <= res[-1][1]:
                res[len(res) - 1] = [res[-1][0], max(res[-1][1], intervals[i][1])]
            else:
                res.append(intervals[i])
        return res
        
            

                
            
        
        
# @lc code=end


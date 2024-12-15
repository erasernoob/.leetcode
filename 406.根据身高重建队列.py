#
# @lc app=leetcode.cn id=406 lang=python3
#
# [406] 根据身高重建队列
#

# @lc code=start
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # 首先先按照元组的值从大到小进行排序
        que = []
        people.sort(key=lambda x : (-x[0], x[1])) # 当元组的值相等的时候，根据x[1]也就是k从小到大的排列
        for p in people:
            que.insert(p[1], p) # 直接将第二个参数k作为最后结果的索引，因为在之前已经对people排好序了
        return que

        
        
        

        
# @lc code=end


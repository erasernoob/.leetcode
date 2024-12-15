#
# @lc app=leetcode.cn id=763 lang=python3
#
# [763] 划分字母区间
#

# @lc code=start
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        # get the last index of the every element of the str
        last_index = {}
        for i, el in enumerate(s):
            last_index[el] = i

        res = []
        left = 0
        right = 0
        for i, el in enumerate(s):
            right = max(right, last_index[el])
            if right == i: # 到达了最远的一个字母
                res.append(right - left + 1)
                left = i + 1
        return res
            
        
# @lc code=end


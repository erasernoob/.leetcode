#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#

# @lc code=start
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res = []
        path = []
        def backtrack(index, current_sum):
            if current_sum == target:
                self.res.append(path.copy())
                return
            
            for i in range(index, len(candidates)):
                current_sum += candidates[i]
                if current_sum > target: 
                    current_sum -= candidates[i]
                    continue
                path.append(candidates[i])
                backtrack(i, current_sum)
                current_sum -= candidates[i]
                path.pop()
        backtrack(0, 0)
        return self.res
        


            
                    
                
        
# @lc code=end


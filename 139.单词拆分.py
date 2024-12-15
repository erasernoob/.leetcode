#
# @lc app=leetcode.cn id=139 lang=python3
#
# [139] 单词拆分
#

# @lc code=start
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        # 记忆化搜索
        memory = [-1] * (len(s) + 1) 
        def backtrack(start_index : int) -> bool:
            if start_index >= len(s):
                return True
            
            # 开始遍历同层级别的树
            for i in range(start_index, len(s) + 1):
                if memory[start_index] != -1:
                    return memory[start_index]
                word = s[start_index : i + 1]
                if word in word_set and backtrack(i + 1) == True:
                    return True
            
            memory[start_index] = False
            return False
        return backtrack(0)







        

                
                
                


        
            
        
# @lc code=end


#
# @lc app=leetcode.cn id=860 lang=python3
#
# [860] 柠檬水找零
#

# @lc code=start
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        # record the numbers of the money
        sum10 = 0
        sum5 = 0
        sum20 = 0
        for i in bills:
            if i == 5: sum5 += 1
            if i == 10: 
                if sum5 == 0: return False
                sum5 -= 1
                sum10 += 1
            if i == 20:
                if sum5 == 0: return False
                if sum10 == 0:
                    if sum5 < 3: return False
                    else: 
                        sum5 -= 3
                        continue
                if sum10 >= 1:
                    sum10 -= 1
                    sum5 -= 1
        return True
                        
                        
                

                
                    
                    
        

        
# @lc code=end


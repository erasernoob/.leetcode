#
# @lc app=leetcode.cn id=738 lang=python3
#
# [738] 单调递增的数字
#

# @lc code=start
class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        # 直接使用字符串切片拼接法则
        # 在python中字符串是不能更改的
        str_num = str(n)
        for i in range(len(str_num) - 1, 0, -1):
            if str_num[i] < str_num[i-1]:
                str_num = str_num[i:] + str(int(str_num[i - 1]) - 1) + "9"* (len(str_num) - i)
        return int(str_num)
        




            
            
            
        
# @lc code=end


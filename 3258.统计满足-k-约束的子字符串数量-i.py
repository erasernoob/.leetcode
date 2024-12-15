#
# @lc app=leetcode.cn id=3258 lang=python3
#
# [3258] 统计满足 K 约束的子字符串数量 I
#

# @lc code=start
class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        # sliding window
        cnt = [0,0]
        left = 0
        ans = 0
        for i, c in enumerate(s):
            cnt[ord(s[i]) & 1] += 1
            while(cnt[0] > k and cnt[1] > k):
                cnt[ord(s[left]) & 1] -= 1
                left += 1
            ans += i - left + 1
        return ans
            
            
        
        
# @lc code=end


/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p = headA;
        ListNode* q = headB;
        int flag1 = 0, flag2 = 0;
        while(q != p) {
            if(p == nullptr && flag1 == 1 && q == nullptr && flag2 == 1) {
                flag1 = 1;
            } 
            if(p == nullptr && flag1 == 0) {
                p = headB;
                flag1 = 1;
            } else {
                p = p->next;
            } 
            if(q == nullptr && flag2 == 0) {
                q = headA;
                flag2 = 1;
            } else {
                q = q->next;
            }
        }
        return q;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=160 lang=java
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

    

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        // put the two LinkList together 
        // 1. AB  2. BA
        ListNode A = headA;
        ListNode B = headB;
        while(A != B) {
            if(A != null) {
                A = A.next;
            } else {
                A = headB;
            }
            if(B != null) {
                B = B.next;
            } else {
                B = headA;
            }
        return A;
    }
}
// @lc code=end


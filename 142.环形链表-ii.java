/*
 * @lc app=leetcode.cn id=142 lang=java
 *
 * [142] 环形链表 II
 */

// @lc code=start

import java.util.HashSet;

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        // 1. fast and slowIndex fast gets 2 
        ListNode fast = head;
        ListNode slow = head;
        while(fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if(fast == slow) {
                ListNode index1 = head;
                ListNode index2 = fast; // start from the encounter node
                while(index1 != index2) {
                    index1 = index1.next;
                    index2 = index2.next;
                }
                return index1;

            } // when encounter the two pointer 
        }
        return null;
    }
}
// @lc code=end


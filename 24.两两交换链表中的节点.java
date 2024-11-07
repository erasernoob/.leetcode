/*
 * @lc app=leetcode.cn id=24 lang=java
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    // need to draw a map to portrayed the way to move specificlly
    // cur -> * -> *-> * * * *
    // what we changed is the pointer's directon, don't think like change the entity node
    public ListNode swapPairs(ListNode head) {
            ListNode dummyHead = new ListNode();
            dummyHead.next = head;
            // 1. cur.next = cur.next.next
            ListNode cur = dummyHead; // cur is the fake HeadNode in order to prefix these node 
            while(cur.next != null && cur.next.next != null) {
                ListNode tmp1 = cur.next;
                ListNode tmp2 = cur.next.next;
                cur.next = tmp2;
                tmp1.next = tmp2.next;
                cur.next.next = tmp1;

                cur = cur.next.next;
            }
            return dummyHead.next;
        }
}
// @lc code=end


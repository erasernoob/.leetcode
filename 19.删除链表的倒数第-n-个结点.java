/*
 * @lc app=leetcode.cn id=19 lang=java
 *
 * [19] 删除链表的倒数第 N 个结点
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
    // via the fast/low index pointer to get the last nth node
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummyHead = new ListNode();
        dummyHead.next = head;
        ListNode fastNode = dummyHead;
        ListNode lowNode = fastNode;

        for (int i = 0; i < n+1; i++) {
            fastNode = fastNode.next;
        }

        while(fastNode != null) {
            fastNode = fastNode.next;
            lowNode = lowNode.next;
        }

        lowNode.next = lowNode.next.next;
        return dummyHead.next;
    }
}
// @lc code=end


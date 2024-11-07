/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fastNode = head;
        ListNode* slowNode = head;
        while(fastNode != NULL && fastNode->next != NULL) {
            fastNode = fastNode->next->next;
            slowNode = slowNode->next;
            if(slowNode == fastNode) {
                ListNode* counter = slowNode;
                ListNode* index = head;
                while(counter != index) {
                    counter = counter->next;
                    index = index->next;
                    
                }       
                return counter;
            }
        }
        return NULL;
    }
};
// @lc code=end


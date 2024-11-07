/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use the double index the fast index go first , and it will go n + 1 step,
        // the the slow index and the fast one goes together, when the fast one is at 
        // the end of the string then the slow one is at the last nth node
        // AB = l , ob = n, the slow one will have the (l - n) = ao
        // use the non dummyHead
        if(head == nullptr || head->next == nullptr) {
            return nullptr;
        } 

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* p = head;
        ListNode* pre_slow = slow;


        for (size_t i = 0; i < n; i++) {
            fast = fast->next;
        }

        while(fast != nullptr) {
            pre_slow = slow;
            fast = fast->next;
            slow = slow->next;
        }
        pre_slow->next = slow->next;
        
        return p;
    }
};
// @lc code=end


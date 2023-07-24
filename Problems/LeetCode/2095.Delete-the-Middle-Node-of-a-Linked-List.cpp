// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow = head, *fast = head, *pre_slow = nullptr;
        while(fast && fast->next) {
            pre_slow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(!pre_slow) {
            return nullptr;
        }
        pre_slow->next = slow->next;
        return head;
    }
};
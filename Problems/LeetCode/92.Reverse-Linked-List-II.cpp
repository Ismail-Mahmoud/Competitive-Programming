// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int idx = 1;
        ListNode* cur = head;
        ListNode* pre = nullptr;

        while(idx < left) {
            pre = cur;
            cur = cur->next;
            ++idx;
        }

        ListNode* r_tail = cur;
        ListNode* pre_left = pre;
        
        while(idx <= right) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            ++idx;
        }
        
        ListNode* r_head = pre;
        if(pre_left) pre_left->next = r_head;
        else head = r_head;
        r_tail->next = cur;

        return head;
    }
};

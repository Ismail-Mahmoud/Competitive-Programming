// https://leetcode.com/problems/partition-list/

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
    struct Partition {
        ListNode* head;
        ListNode* last;
    } part[2];
public:
    ListNode* partition(ListNode* head, int x) {
        for(int i = 0; i < 2; ++i) {
            part[i].head = part[i].last = new ListNode();
        }
        ListNode* cur = head;
        while(cur) {
            if(cur->val < x) {
                part[0].last->next = cur;
                part[0].last = cur;
            }
            else {
                part[1].last->next = cur;
                part[1].last = cur;
            }
            cur = cur->next;
        }
        part[1].last->next = nullptr;
        part[0].last->next = part[1].head->next;
        return part[0].head->next;
    }
};

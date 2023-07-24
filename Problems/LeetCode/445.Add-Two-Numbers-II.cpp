// https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* preHead = new ListNode();
        ListNode* cur = preHead;
        int sum, dig, carry = 0;
        
        while(l1 || l2 || carry) {
            sum = carry;
            if(l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            dig = sum % 10;
            carry = sum >= 10;

            cur->next = new ListNode(dig);
            cur = cur->next;
        }

        return reverse(preHead->next);
    }

    ListNode* reverse(ListNode* node) {
        ListNode* prev = nullptr;
        ListNode* next;
        while(node) {
            next = node->next;
            node->next = prev;
            prev = node;
            node = next;
        }
        return prev;
    }
};
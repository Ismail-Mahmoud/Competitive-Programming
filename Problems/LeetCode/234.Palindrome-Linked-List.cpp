// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = head;
        slow = reverse(slow);
        while(slow) {
            if(slow->val != fast->val) {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
    
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
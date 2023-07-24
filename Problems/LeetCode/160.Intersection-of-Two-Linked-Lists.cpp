// https://leetcode.com/problems/intersection-of-two-linked-lists/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) {
            return nullptr;
        }
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        while(a != b) {
            cout << a->val << " " << b->val << endl;
            a = a->next;
            b = b->next;
            
            if(a == b) {
                return a;
            }
            
            if(a == nullptr) {
                a = headB;
            }
            if(b == nullptr) {
                b = headA;
            }
        }
        return a;
    }
};
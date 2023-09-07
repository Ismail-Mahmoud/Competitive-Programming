// https://leetcode.com/problems/split-linked-list-in-parts/

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* node = head;
        while(node) {
            ++n;
            node = node->next;
        }
        int q = n / k, r = n % k;
        vector<ListNode*> ans(k, nullptr);
        node = head;
        for(int i = 0; i < k && node; ++i, --r) {
            ans[i] = node;
            ListNode* last;
            for(int j = 0; j < q + (r > 0); ++j) {
                last = node;
                node = node->next;
            }
            last->next = nullptr;
        }
        return ans;
    }
};

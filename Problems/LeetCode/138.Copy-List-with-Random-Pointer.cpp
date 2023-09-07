// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }

        Node* cpd_head = new Node(head->val);
        Node* cpd_pre = cpd_head;
        Node* org_node = head->next;
        unordered_map<Node*, Node*> equivalent = {
            {head, cpd_head},
            {nullptr, nullptr}
        };

        // Set `next`
        while(org_node) {
            Node* cpd_node = new Node(org_node->val);
            equivalent[org_node] = cpd_node;
            cpd_pre->next = cpd_node;
            org_node = org_node->next;
            cpd_pre = cpd_pre->next;
        }
        cpd_pre->next = nullptr;
        
        org_node = head;
        Node* cpd_node = cpd_head;

        // Set `random`
        while(org_node) {
            Node* cpd_random = equivalent[org_node->random];
            cpd_node->random = cpd_random;
            org_node = org_node->next;
            cpd_node = cpd_node->next;
        }

        return cpd_head;
    }
};

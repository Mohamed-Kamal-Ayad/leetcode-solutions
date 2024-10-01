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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*, bool> visited;
        ListNode* curr = head;
        while (curr != NULL) {
            if (visited.find(curr) != visited.end()) {
                return true;
            }
            visited[curr] = true;
            curr = curr->next;
        }
        return false;
    }
};
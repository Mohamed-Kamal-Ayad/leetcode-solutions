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
    void reorderList(ListNode* head) {
        deque<ListNode*> lists;
        ListNode* curr = head->next;
        while (curr != NULL) {
            lists.push_back(curr);
            curr = curr->next;
        }
        ListNode* f;
        ListNode* b;
        ListNode* nlist = head;
        while (!lists.empty()) {
            f = lists.front();
            b = lists.back();
            b->next = f;
            nlist->next = b;
            nlist = f;
            nlist->next = NULL;
            lists.pop_back();
            if (!lists.empty()) {
                lists.pop_front();
            }
        }
    }
};
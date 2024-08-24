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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        if (list1 == NULL && list2 == NULL) {
            return head;
        } else if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        }
        head = new ListNode();
        ListNode* curr = head;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while (temp1 && temp2) {
            curr->next = temp1->val <= temp2->val ? temp1 : temp2;
            if (temp1->val <= temp2->val) {
                temp1 = temp1->next;
            } else {
                temp2 = temp2->next;
            }
            curr = curr->next;
        }

        if (temp1 == NULL) {
            curr->next = temp2;
        } else {
            curr->next = temp1;
        }
        
        return head->next;
    }
};
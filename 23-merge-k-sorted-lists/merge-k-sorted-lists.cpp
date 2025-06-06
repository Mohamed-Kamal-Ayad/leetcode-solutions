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
        ListNode* dummy = new ListNode();
        ListNode* head = dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                head->next = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                list2 = list2->next;
            }
            head = head->next;
        }

        if (list1) {
            head->next = list1;
        } else {
            head->next = list2;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1) {
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i += 2) {
                mergedLists.push_back(mergeTwoLists(
                    lists[i], (i + 1) < lists.size() ? lists[i + 1] : NULL));
            }
            lists = mergedLists;
        }
        return lists[0];
        // if(lists.empty()) return NULL;
        // int i = 1;
        // while (i < lists.size()) {
        //     lists[i] = mergeTwoLists(lists[i], lists[i - 1]);
        //     i++;
        // }
        // return lists[lists.size() - 1];
    }
};
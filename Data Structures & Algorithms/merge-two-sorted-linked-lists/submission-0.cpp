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
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
         
        ListNode *prev1 = new ListNode(), *curr1 = list1, *curr2 = list2, *nxt2;

        while (curr2 != nullptr) {
            if (curr1 == nullptr || curr2->val < curr1->val) {
                nxt2 = curr2->next;

                prev1->next = curr2;
                curr2->next = curr1;
                
                prev1 = curr2;
                curr2 = nxt2;
            } else {
                prev1 = curr1;
                curr1 = curr1->next;
            }
        }

        return (list2->val < list1->val) ? list2 : list1;
    }
};

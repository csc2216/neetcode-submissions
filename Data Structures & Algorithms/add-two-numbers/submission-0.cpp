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
        ListNode *st = new ListNode(), *curr1 = l1, *curr2 = l2, *prev_sum = st, *curr_sum;
        int add = 0, carry = 0;
        while (curr1 != nullptr || curr2 != nullptr || carry == 1) {
            if (curr1 != nullptr) add += curr1->val;
            if (curr2 != nullptr) add += curr2->val;
            add += carry;

            if (add >= 10) {
                carry = 1;
                add -= 10;
            } else carry = 0;
            curr_sum = new ListNode(add);
            prev_sum->next = curr_sum;

            prev_sum = curr_sum;
            add = 0; 
            if (curr1 != nullptr) curr1 = curr1->next;
            if (curr2 != nullptr) curr2 = curr2->next;
        }
        return st->next;
    }
};

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        ListNode *st = &dummy;
        st->next = head;

        ListNode *prev_k_end = st, *curr_k_start, *curr_k_end, *next_k_start; 
        ListNode *prev, *curr, *nxt;
        while (true) {
            int i = 0;
            curr_k_end = prev_k_end;
            while (i != k) {
                if (curr_k_end->next != nullptr) {
                    curr_k_end = curr_k_end->next;
                    i++;
                } else break;
            }
            if (i == k) {
                curr_k_start = prev_k_end->next;
                prev_k_end->next = curr_k_end;
                next_k_start = curr_k_end->next;

                prev = next_k_start;
                curr = curr_k_start;
                while (curr != next_k_start) {
                    nxt = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = nxt;
                }

                prev_k_end = curr_k_start;
            } else break;
        }

        return st->next;
    }
};

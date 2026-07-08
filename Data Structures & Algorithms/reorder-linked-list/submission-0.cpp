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
        if (head->next == nullptr) return;

        ListNode *slow = head, *fast = head->next;
        ListNode *mid;
        while(fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) break;
            fast = fast->next->next;
        }
        mid = slow;

        ListNode *prev = nullptr, *curr = mid, *nxt;
        ListNode *end;
        while (curr != nullptr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        end = prev;

        ListNode *l = head, *r = end, *lnxt, *rnxt;
        while (r != mid) {
            lnxt = l->next; rnxt = r->next;
            if (l != mid) {
                l->next = r;
                r->next = lnxt;

                l = lnxt;
                r = rnxt;
            } else {
                l->next = r;
                r->next = nullptr; 
                break;
            }
        } 

        return;
    }
};


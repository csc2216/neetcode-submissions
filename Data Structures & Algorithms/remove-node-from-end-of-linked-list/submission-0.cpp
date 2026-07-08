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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == nullptr) {
            return nullptr;
        }
        
        ListNode *st = new ListNode(0, head);
        ListNode *l = st, *r = st;
        int i = 0;
        while (i < n) {
            r = r->next;
            i++;
        }
        while (r->next != nullptr) {
            l = l->next;
            r = r->next;
        }
        l->next = l->next->next;

        head = st->next;
        return head;
    }
};

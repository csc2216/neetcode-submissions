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
        Node *st = new Node(0), *curr_ori = head, *prev_cop = st, *curr_cop;
        unordered_map<Node*, Node*> node_pair;

        while (curr_ori != nullptr) {
            curr_cop = new Node(curr_ori->val);
            prev_cop->next = curr_cop;

            node_pair[curr_ori] = curr_cop;

            curr_ori = curr_ori->next;
            prev_cop = curr_cop;
        }

        node_pair[nullptr] = nullptr;
        curr_ori = head; curr_cop = st->next;
        while (curr_ori != nullptr) {
            curr_cop->random = node_pair[curr_ori->random];

            curr_ori = curr_ori->next;
            curr_cop = curr_cop->next;
        }

        return st->next;     
    }
};

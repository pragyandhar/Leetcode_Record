/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        Node* curr = head;
        while (curr != NULL) {
            if (curr -> child != NULL) {
                // 1. Initialise a new node "next"
                Node* next = curr -> next;
                // 2. Use recursion to flatten the child
                curr -> next = flatten(curr -> child);
                // 3. For reverse connection
                curr -> next -> prev = curr;
                // 4. There is no child of the current node
                curr -> child = NULL;

                while (curr -> next != NULL) {
                    curr = curr -> next;
                }

                if (next != NULL) {
                    curr -> next = next;
                    next -> prev = curr;
                }
            }
            curr = curr -> next;
        }
        return head;
    }
};
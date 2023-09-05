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
        if (!head) {
            return nullptr;
        }

        unordered_map<Node*, Node*> nodeMap;

        Node* dummy = new Node(0);
        Node* current = head;
        Node* newCurrent = dummy;

        while (current) {
            Node* newNode = new Node(current->val);
            nodeMap[current] = newNode;
            newCurrent->next = newNode;
            newCurrent = newCurrent->next;
            current = current->next;
        }

        current = head;
        newCurrent = dummy->next;

        while (current) {
            newCurrent->random = nodeMap[current->random];
            current = current->next;
            newCurrent = newCurrent->next;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};
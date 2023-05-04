class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head; // edge cases

        int length = 1; // length of the list
        ListNode* curr = head;
        while(curr->next) {
            length++;
            curr = curr->next;
        }
        curr->next = head; // make the list circular

        k %= length; // reduce the number of rotations
        for(int i = 0; i < length - k; i++) curr = curr->next; // find the new tail

        ListNode* new_head = curr->next; // set the new head
        curr->next = nullptr; // break the circle

        return new_head;
    }
};


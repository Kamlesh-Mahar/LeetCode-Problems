class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) return head;nd of the list
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }
        int rotations = k % len;
        if (rotations == 0) return head;
        tail->next = head;
        ListNode* new_tail = head;
        for (int i = 0; i < len - rotations - 1; i++) {
            new_tail = new_tail->next;
        }
        head = new_tail->next;
        new_tail->next = NULL;
        
        return head;
    }
};

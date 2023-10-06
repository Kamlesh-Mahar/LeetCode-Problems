class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = NULL;
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);
        return merge(left, right);
    }
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* current = &dummy;

        while (left && right) {
            if (left->val < right->val) {
                current->next = left;
                left = left->next;
            } else {
                current->next = right;
                right = right->next;
            }
            current = current->next;
        }

        if (left)
            current->next = left;
        else
            current->next = right;

        return dummy.next;
    }
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* kthNode = nullptr;
        int count = 1;
        while (count < k) {
            p1 = p1->next;
            count++;
        }
        kthNode = p1;
        while (p1->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        int temp = kthNode->val;
        kthNode->val = p2->val;
        p2->val = temp;
        
        return head;
    }
};
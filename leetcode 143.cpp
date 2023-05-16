class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        
        ListNode* mid = findMiddle(head);
        ListNode* reversed = reverseList(mid->next);
        mid->next = nullptr;
        
        mergeLists(head, reversed);
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void mergeLists(ListNode* l1, ListNode* l2) {
        while (l1 && l2) {
            ListNode* l1Next = l1->next;
            ListNode* l2Next = l2->next;
            
            l1->next = l2;
            l2->next = l1Next;
            
            l1 = l1Next;
            l2 = l2Next;
        }
    }
};

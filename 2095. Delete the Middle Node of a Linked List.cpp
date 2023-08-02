class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next->next!=NULL && fast->next->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};
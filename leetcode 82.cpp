class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    
    ListNode* temp_List = new ListNode(0);
    temp_List->next = head;
    ListNode* prev = temp_List;
    ListNode* curr = head;
    
    while (curr) {
        if (curr->next && curr->val == curr->next->val) {
            int val = curr->val;
            while (curr && curr->val == val) {
                ListNode* temp_Node = curr;
                curr = curr->next;
                delete temp_Node;
            }
            prev->next = curr;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    
    head = temp_List->next;
    delete temp_List;
    return head;
}

};
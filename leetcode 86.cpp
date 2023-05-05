class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;

        ListNode temphead1(0), temphead2(0);
        ListNode *temp_Node1 = &temphead1, *temp_Node2= &temphead2;

        while(head){
            if(head->val < x){
                temp_Node1->next = head;
                temp_Node1 = temp_Node1->next;
            }
            else{
                temp_Node2->next = head;
                temp_Node2 = temp_Node2->next;
            }
            head = head->next;
        }

        temp_Node1->next = temphead2.next;
        temp_Node2->next = NULL;

        return temphead1.next;
    }
};
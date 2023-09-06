/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode*  current = head;
        while(current){
            length++;
            current = current->next;
        }

        int part = length/k;
        int extraNodes = length % k;

        vector<ListNode*> result;

        current = head;
        ListNode* prev = nullptr;

        for(int i = 0; i<k; i++){
            result.push_back(current);
            int currentSize = part + (i<extraNodes ? 1: 0);

            for(int j = 0; j< currentSize; j++){
                prev = current; 
                current = current->next;
            }

            if(prev){
                prev->next = nullptr;
            }
        }
        return result;
    }
};
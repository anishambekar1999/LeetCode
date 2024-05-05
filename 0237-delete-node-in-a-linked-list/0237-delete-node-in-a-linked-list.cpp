/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        ListNode* temp = node;
        ListNode* curr = NULL;

        while(temp->next!=NULL)
        {
            temp->val = (temp->next)->val;
            curr = temp;
            temp = temp->next;
        }
        
        curr->next = NULL;
    }
};
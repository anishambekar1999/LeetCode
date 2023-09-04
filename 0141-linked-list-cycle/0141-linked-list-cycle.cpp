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
    bool hasCycle(ListNode *head) {
        
        if(head==NULL)
            return false;

        if(head->next==NULL)
            return false;

        ListNode* slow=head;
        ListNode* fast=head;
        bool flag=true;

        while(true)
        {   
            if(flag==false && fast==slow)
            {
                return true;
            }

            flag=false;
            if(fast && fast->next)
                fast=(fast->next)->next;
            else
                break;

            slow=slow->next;
        }

        return false;
    }
};
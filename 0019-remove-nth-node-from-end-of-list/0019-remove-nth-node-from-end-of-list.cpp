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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fast = head;
        for(int i=0;i<n;i++)
            fast = fast->next;

        if(fast == NULL)
        {
            ListNode* temp = head->next;
            head->next = NULL;
            head = temp;
        }
        else
        {
            ListNode* slow = head;
            while(fast->next)
            {
                fast = fast->next;
                slow = slow->next;
            }

            ListNode* temp = slow->next;
            slow->next = temp->next;
            temp->next = NULL;
        }

        return head;
    }
};
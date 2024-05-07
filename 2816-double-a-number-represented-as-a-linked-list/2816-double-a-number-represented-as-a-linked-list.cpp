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
    ListNode* doubleIt(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = head->next;

        if(head!=NULL && head->next!=NULL)
        {
            while(next)
            {
                curr->next = prev;
                prev = curr;
                curr = next;
                next = curr->next;
            }
            curr->next = prev;
        }

        head = curr;

        int carry = 0;
        while(curr)
        {
            int x = curr->val * 2 + carry;
            curr->val = x%10;
            carry = x/10;
            prev = curr;
            curr = curr->next;
        }

        if(carry > 0)
        {
            ListNode* temp = new ListNode(carry);
            prev->next = temp;
        }

        prev = NULL;
        curr = head;
        next = head->next;

        if(head!=NULL && head->next!=NULL)
        {
            while(next)
            {
                curr->next = prev;
                prev = curr;
                curr = next;
                next = curr->next;
            }
            curr->next = prev;
        }

        return curr;
    }
};
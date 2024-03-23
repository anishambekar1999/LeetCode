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
    void reorderList(ListNode* head) {
        
        if(!(head->next))
            return;
        if(!((head->next)->next))
            return;
        
        ListNode* temp=head;
        stack<ListNode*>st;
        int n=0;
        
        while(temp)
        {
            n++;
            st.push(temp);
            temp=temp->next;
        }
        
        temp=head;
        for(int i=0;i<(n/2);i++)
        {
            ListNode* t=st.top();
            st.pop();
            
            ListNode* t2=temp->next;
            temp->next=t;
            
            if(t!=t2)
            {
                ListNode* t3=st.top();
                t3->next=NULL;
                t->next=t2;
            }
            else
                t->next=NULL;
            
            temp=t2;
        }
    }
};










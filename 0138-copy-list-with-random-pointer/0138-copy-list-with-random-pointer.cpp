/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head==NULL)
            return head;

        Node* temp=head;
        while(temp!=NULL)
        {
            Node* n=new Node(temp->val);

            Node* tempN = temp->next;
            temp->next=n;
            n->next=tempN;
            temp=n->next;
        }

        temp=head;
        while(temp!=NULL) 
        {
            cout<<temp->val<<" ";
            temp=temp->next;
        }

        temp=head;
        while(temp!=NULL)
        {
            if(temp->random)
                (temp->next)->random = (temp->random)->next;
            else
                (temp->next)->random=NULL;
            temp=(temp->next)->next;
        }

        temp=head;
        Node* curr1=temp;
        Node* curr2=temp->next; 
        Node* newHead=curr2;

        while(curr1)
        {
            curr1->next=curr2->next;
            if(curr2->next)
                curr2->next=(curr2->next)->next;
            else
                curr2->next=NULL;
            
            curr1=curr1->next;
            curr2=curr2->next;
        }

        return newHead;
    }
};
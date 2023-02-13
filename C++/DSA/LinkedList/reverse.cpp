//Reverse a Linked List 
 //iterative approach ..... 

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
    ListNode* reverseList(ListNode* head) {
        
         if(head == NULL || head->next == NULL)
                   return head;
        
        ListNode* tmp=head;
        ListNode* prev=NULL,*cur=head; 
        
            while(tmp)
            {
                tmp=tmp->next;
                cur->next=prev;
                prev=cur;
                cur=tmp;
            }
        return prev;
    }
};



// Recursive Approach ... 

ListNode* reverse(ListNode* head)
{
	if(head==NULL || head->next==NULL)
			return head;
	ListNode *p=reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return p;
} 
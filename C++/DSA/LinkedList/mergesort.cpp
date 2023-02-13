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
   
    ListNode* merge(ListNode* tmp ,ListNode* mid)
    {
        ListNode* head=new ListNode();
        ListNode* l=head;
        
        if(!tmp)
            return mid;
        if(!mid)
            return tmp;
        
        while(tmp && mid)
        {
            if(tmp->val <= mid->val)
            {
                head->next=tmp;
                tmp=tmp->next;
            } 
            else
            {
                head->next=mid;
                mid=mid->next;
            }
            head=head->next;
        }
        if(tmp)
            head->next=tmp;
        if(mid)
            head->next=mid;
        
        return l->next;
    }
   ListNode* recur(ListNode* head)
    {
        if( !head || !head->next)return head ;
        
        ListNode* mid=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        
        while(fast && fast->next)
        {
            prev=mid;
            mid=mid->next;
            fast=fast->next->next;
        }
        
        prev->next=NULL;
        head=recur(head);
        mid=recur(mid);
        head=merge(head,mid);
        return head;
    }
    ListNode* sortList(ListNode* head) {
    ListNode* tmp;
       tmp=recur(head);
        return tmp;
    }
};
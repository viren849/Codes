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
    bool isPalindrome(ListNode* head) {
        
        ListNode *s=head,*f=head;
        while(f->next&&f->next->next)
        {    s=s->next;
             f=f->next->next;
        }
        ListNode *prev=NULL,*d=head,*nt=s->next,*i=s->next;
        while(nt)
        {
            nt=nt->next;
            i->next=prev;
            prev=i;
            i=nt;
        }
        while(prev)
        {
            if(d->val!=prev->val)
                return false;
            prev=prev->next;
            d=d->next;
        }
        return true;
    }
};
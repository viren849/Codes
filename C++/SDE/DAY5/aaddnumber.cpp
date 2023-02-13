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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* head=l2;
        int c=0,x,y;
        ListNode *h=new ListNode(0);
        ListNode *p=h;
        while(l1 || l2)
        {
            x=0;y=0;
          if(l1)
              x=l1->val;
            
              if(l2)
                  y=l2->val;
            
            int t=x+y;
            t+=c;
            c=t/10;
            
            
           ListNode* tmp =new ListNode(t%10);
            h->next=tmp;
            h=h->next;
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
        }
        if(c>0)
            h->next=new ListNode(c);
        return p->next;
    }
};
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
        if(head==NULL)return false;
        ListNode *p=head,*p1=head->next;
        while(p!=p1)
        {
            
            if(!p1||!p1->next)return false;
         p= p->next;p1=p1->next->next;
        }
        return true;
    }
    
};
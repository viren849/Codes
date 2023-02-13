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
     ListNode *h1=head,*prev=NULL,*nt=head;
        if(h1==NULL)return NULL;
        while(nt)
        {
            nt=nt->next;
            h1->next=prev;
            prev=h1;
            h1=nt;
        }
        return prev;
    }
};




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
     ListNode *h1=head,*prev=NULL,*nt=head;
        if(h1==NULL)return NULL;
        while(nt)
        {
            nt=nt->next;
            h1->next=prev;
            prev=h1;
            h1=nt;
        }
        return prev;
    }
};
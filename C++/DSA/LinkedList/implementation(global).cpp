
//using local variable.......

#include<bits/stdc++.h>
using namespace std;
struct Node{
  int data;
  struct Node* next;

  Node(int data)
  {
    this->data=data;
    next=NULL;
  }
};


void print(Node* head)
{
  Node* tmp=head;
  while(tmp)
  {
    cout<<tmp->data<<" ";
    tmp=tmp->next;
  }
}


Node* push(Node* head,int n)
{
  Node* tmp=new Node(n);
  tmp->next=head;
  return tmp;
}

Node* push2(Node* head,int n)
{
  Node* nd=new Node(n);
  if(head==NULL)
     return nd;

  Node* tmp=head;

  while(tmp->next)
  {
    tmp=tmp->next;
  }
  tmp->next=nd;
  return head;
}
int main()
{
  int n;
  cin>>n;
  Node *head=NULL;

  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    head=push2(head,x);
  }

  print(head);
}
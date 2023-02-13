
//using global variable.......

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

 Node *head=NULL;

void print(Node* head)
{
  Node* tmp=head;
  while(tmp)
  {
    cout<<tmp->data<<" ";
    tmp=tmp->next;
  }
}


void push(int n)
{
  Node* tmp=new Node(n);
  tmp->next=head;
  head=tmp;
}

void push2(int n)
{
  Node* nd=new Node(n);
  if(head==NULL)
  {
    head=nd;
    return;
  }
  Node* tmp=head;

  while(tmp->next)
  {
    tmp=tmp->next;
  }
  tmp->next=nd;
}
int main()
{
  int n;
  cin>>n;
 
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    push2(x);
  }

  print(head);
}
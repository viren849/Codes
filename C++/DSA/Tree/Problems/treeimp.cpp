#include<bits/stdc++.h>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

  Node(int data)
   {
       this->data=data;
       left=right=NULL;
   }
};


int cnt=0;

Node* insert(int x,Node* root)
{
    
   Node* tmp=new Node(x);
  
   if(!root)
       {
        root=tmp;
        cnt++;
      }     
   else
     {  
        if(cnt%2 !=0)
        root->left=insert(x,root->left);
      else
        root->right=insert(x,root->right);
     }
     return root;
}
 
Node* root=NULL;

void print(Node* root)
{
   if(!root)return ;
   cout<<root->data<<" ";
   print(root->left);
   print(root->right);
}

int main()
{ 

    int n;
    cin>>n;
    
    for(int i=0;i<n;i++)
      {  
          int x;
          cin>>x;
         root=insert(x,root); 
      }
      print(root);
}
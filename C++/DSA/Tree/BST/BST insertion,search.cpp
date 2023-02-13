
//Binary Search Tree....

#include<bits/stdc++.h>
using namespace std;

struct BST
{
  int data;
  BST* left;
  BST* right;

  BST()
  {
    data=0;
    left=right=NULL;
  }

  BST(int data)
  {
    this->data=data;
    left=right=NULL;
  }
};

void inprint(BST* root)
{
    if(root==NULL)return;

    inprint(root->left);
    cout<<root->data<<" ";
    inprint(root->right);
}

BST* insert(BST *root,int key)
{
    if(root == NULL)
        root=new BST(x);
    else if(key <= root->data)
      root->left=insert(root->left,key);
    else 
      root ->right=insert(root->right,key);
    
    return root;
}

bool search(BST* root,int x)
{
      if(root==NULL)
        return false;
      if(x==root->data)
        return true;
      if(x < root->data)
       return search(root->left,x);
      else return search(root->right,x);
}

int main()
{
  int n;
  cin>>n;
  
  BST* root=NULL;

  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    
    root=insert(root,x);
  }
  cout<<search(root,10);
  cout<<"  "<<search(root,3);
  inprint(root);
}

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

BST* findmin(BST* root)
{
     while(root->left)
      root=root->left;
    return root;
}
BST* insert(BST *root,int x)
{
    if(root == NULL)
        root=new BST(x);
    else if(x <= root->data)
      root->left=insert(root->left,x);
    else 
      root ->right=insert(root->right,x);
    
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
BST* deleteNode(BST* root,int key)
{
     if(root == NULL)
      return root;
    if(key < root->data)
      root->left=deleteNode(root->left,key);
    else if(key > root->data)
      root->right=deleteNode(root->right,key);
    else
    {
       //found the key...
       if(root->left == NULL and root->right == NULL)
       {
           delete root;
           root=NULL;
       }
       else if(root->left ==NULL)
       {
            BST *tmp = root;
            root=root->right;
            delete tmp;
       }
        else if(root->right ==NULL)
        {
            BST *tmp = root;
            root=root->left;
            delete tmp;
        }
        else
        {
            //find max from left subtree or 
            //find min from right subtree ;

            BST* tmp=findmin(root->right);
            root->data=tmp->data;
            root->right=deleteNode(root->right,tmp->data);
        }
        return root;
    }
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
  cout<<"  "<<search(root,3)<<endl;
  inprint(root);
  deleteNode(root,4);
  cout<<endl;
  inprint(root);
}
#include <bits/stdc++.h>
using namespace std;

//CHILDERN SUM PROPERTY...

void func(Node* rt)
{
    
   if(!rt)return ;
   int child=0;

   if(rt->left)child+=rt->left->val;
   if(rt->right)child+=rt->right->val;

   if(child >= rt->val)
    root->val=child;
   else{
      if(root->left) root->left->val=root->val;
      if(root->right)root->right->val=root->val;
   }

   func(rt->left);
   func(rt->right);

   int tot=0;

   if(root->left)tot+=root->left->val;
   if(root->right)tot+=root->right->val;
   
   if(root->left or root->right)
      root->val=tot;
}
#include <bits/stdc++.h>
using namespace std;

//check for symmetry ....

bool hleper(Node* rt1,Node* rt2)
{
        if(!rt1 or !rt2)
          return rt1==rt2;
        if(rt1->val!=rt2->val) return false;

        return hleper(rt1->left,rt2->right) and 
        hleper(rt1->right,rt1->left);
         
}

bool issymmtery(Node* root)
{
     if(!root)return true;

     return hleper(root->left,root->right);
}
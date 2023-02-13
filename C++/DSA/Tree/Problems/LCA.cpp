#include <bits/stdc++.h>
using namespace std;

//Lowest Common Ancestor....

Node* LCA(Node* rt,Node *p,Node* q)
{
      if(rt==NULL || rt==p || rt==q)
        return rt;

     Node* l=LCA(rt->left,p,q);
     Node* r=LCA(rt->right,p,q);

     if(!l and !r)return NULL;

     if(!l)return r;
     if(!r)return l;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
//check balanced bt
int height(Node* root)
{
    if(!root)
         return 0;
    int lh=height(root->left);
    int rh=height(root->right);
    return 1+max(lh,rh); 
}
  bool check(Node* root)
  {
     if(!root)
        return 1;
    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh) > 1)
        return 0;
    bool l=check(root->left);
    if(!l)return 0;
    bool r=check(root->right);
    if(!r)return 0;
    return 1;
  }
int func(Node* root)
{
    if(!root)
        return 0;
    int lh=func(root->left);
    if(lh==-1)return -1;

    int rh=func(root->right);
    if(rh==-1)return -1;

    if(abs(lh-rh)>1)return -1;

    return 1+max(lh,rh);

}
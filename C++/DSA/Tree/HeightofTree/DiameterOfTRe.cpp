#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	return 0;
}
int lenght=0;
int height(root)
{
	if(root == NULL)return 0;

	return 1+max(height(root->left),height(root->right));
}
void brutediameter(root,int& maxi)
  {
  	   if(!root)
  	   	  return ;
  	   int lh=height(root->left);
  	   int rh=height(root->right);

  	   maxi=max(maxi,lh+rh);

  	   brutediameter(root->left,maxi);
  	   brutediameter(root->right,maxi);

  }
int diametr(Node* root)
{
    if(!root)
        return 0;
    int lh=diametr(root->left);
    int rh=diametr(root->right);
    lenght=max(lenght,lh+rh);
    return max(lh+rh)+1;
}
cout<<lenght;
#include<bits/stdc++.h>
using namespace std;

//124. Binary Tree Maximum Path Sum

//brute force -->O(N^2);
 int sum(TreeNode *root)
    {
        if(!root)return 0;
        int l=sum(root->left);
        int r=sum(root->right);
        l=max(l,0);
        r=max(r,0);
        return max(l,r)+root->val;
    }
    void ans(TreeNode *root,int &mx)
    {
        if(!root)
             return;
        int lh=sum(root->left);
        int rh=sum(root->right);
        lh=max(lh,0);
        rh=max(rh,0);
         mx=max(mx,root->val+lh+rh);
        ans(root->left,mx);
        ans(root->right,mx);

    }
    int maxPathSum(TreeNode* root) {
      int mx=INT_MIN;
        ans(root,mx);
      return mx;
    }


//optimization ...
    o(N);
int  ans(TreeNode *root,int &mx)
    {
        if(!root)
             return 0;
        int lh=ans(root->left,mx);
        int rh=ans(root->right,mx);
        lh=max(lh,0);
        rh=max(rh,0);
         mx=max(mx,root->val+lh+rh);
        
        return max(lh,rh)+root->val;

    }
    int maxPathSum(TreeNode* root) {
      int mx=INT_MIN;
        ans(root,mx);
      return mx;
    }

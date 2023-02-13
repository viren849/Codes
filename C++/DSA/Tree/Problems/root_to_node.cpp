#include <bits/stdc++.h>
using namespace std;

//root to node path 
bool helper(TreeNode* rt,vector<int>&ans,int vl)
 {
      if(!rt)return false;
      
      ans.push_back(rt->val);
      if(rt->val == vl)  
        return true;
      

      int l=helper(rt->left,ans,vl);
      int r=helper(rt->right,ans,vl);

      if(l==false and r==false)
        ans.pop_back();
      return l or r;
  }
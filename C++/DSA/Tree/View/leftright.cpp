
//right view of binary tree....

void dfs(TreeNode* rt,vector<int>&ans,int lev)
  {
      if(!rt)return ;

      if(lev == ans.size())
       ans.push_back(rt->val);
       dfs(rt->right,ans,lev+1);
       dfs(rt->left,ans,lev+1);

  }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }

//left view
void dfs(TreeNode* rt,vector<int>&ans,int lev)
  {
      if(!rt)return ;

      if(lev == ans.size())
       ans.push_back(rt->val);
       dfs(rt->left,ans,lev+1);
       dfs(rt->right,ans,lev+1);

  }
    vector<int> leftSideView(TreeNode* root) {
        vector<int>ans;
        dfs(root,ans,0);
        return ans;
    }
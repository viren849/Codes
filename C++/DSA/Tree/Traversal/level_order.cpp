
//LEVEL ORDER 


vector<vector<int> levelordertraversal(node root)
{
   vector<vector<int>>ans;
   if(root==NULL)return ans;

   queue<node*>q;
   q.push(root);

   while(!q.empty())
   {
   	
   	 vector<int>tmp; 
   	  int s=q.size();
   	  for(int i=0;i<s;i++)
   	  {
     	node* n_root=q.front();
   	  	q.pop();
        tmp.push_back(n_root->val);

   	  	if(n_root->left) q.push(n_root->left);
   	  	if(n_root->right)q.push(n_root->right);

   	  }
   	  ans.push_back(tmp);
   }
   return ans;
}

//one more..

void levelordertraversal(Treenode* root)
{
      if(root == NULL)return ;


      queue<TreeNode*>q;
      q.push(root);

      while(!q.empty())
      {
          TreeNode* tmp=q.front();
           
          v.push_back(tmp->val);

          if(tmp->left)q.push(tmp->left);
          if(tmp->right)q.push(tmp->right);

          q.pop();
      }

      for(int i : v)
         cout<<i<<" ";
}



//USING DFS.....

 void dfs(vector<vector<int>>&ans,TreeNode* root,int lev)
    {
        if(!root)return ;
        if(lev >= ans.size())
            ans.push_back({});
        ans[lev].push_back(root->val);
        dfs(ans,root->left,lev+1);
        dfs(ans,root->right,lev+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>>ans;
        
         if(!root)return ans;
        
         dfs(ans,root,0);
         
         return ans;
    }

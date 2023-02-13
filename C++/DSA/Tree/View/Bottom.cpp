#include <bits/stdc++.h>
using namespace std;

void helper(Node* rt,int ver)
  {
      queue<pair<int,Node*>>q;
      q.push({0,rt});
      
      while(!q.empty())
      {
          auto tmp = q.front();
          
          q.pop();
          
          mp[tmp.first]=tmp.second->data;
          
          if(tmp.second->left)
           q.push({tmp.first-1,tmp.second->left});
          if(tmp.second->right)
          q.push({tmp.first+1,tmp.second->right});
      }
  }
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        vector<int>ans;
        
        if(root==NULL)return ans;
        
        helper(root,0);
        
        for(auto it : mp)
          ans.push_back(it.second);
        return ans;
        
    }
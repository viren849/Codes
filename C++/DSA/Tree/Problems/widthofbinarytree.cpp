#include <bits/stdc++.h>
using namespace std;

//Maximum width of binary tree..

int widthOfBinaryTree(TreeNode* root) {
        int ans=0;

        queue<pair<TreeNode*,int>>q;
        q.push({root,0});

        while(!q.empty())
        {
            int s=q.size();
            int mn=q.front().second;
            int ft,last;
            
            for(int i=0;i<s;i++)
            {
                 
                auto tmp=q.front();
                q.pop();
                
                int id= tmp.second-mn;

                if(i==0)ft=id;
                if(i==s-1)last=id;

                if(tmp.first->left)q.push({tmp.first->left,1LL*id*2+1});
                if(tmp.first->right)q.push({tmp.first->right,1LL*id*2+2});
            }
            ans=max(ans,last-ft+1);
        }
        return ans;
    }
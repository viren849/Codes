#include <bits/stdc++.h>
using namespace std;

//top view of Binary Tree .....

void helper(Node* rt)
{
  map<int,int>mp;

  queue<pair<Node*,int>>q;

  q.push({rt,0});

  while(!q.empty())
  {
    auto tmp=q.front();
    q.pop();

    if(mp.find(tmp.second)==mp.end())
      mp[tmp.second]=tmp.first->data;

    if(tmp.first->left)
      q.push({tmp.first->left,tmp.second-1});
    if(tmp.first->right)
      q.push({tmp.first->right,tmp.second+1})
  }

  
}
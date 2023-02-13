#include<bits/stdc++.h>
using namespace std;
bool dfs(int i,vector<int>adj[],vector<int>&dfsvis,vector<int>&vis)
{
    if(!vis[i])
      {
        vis[i]=1;
        dfsvis[i]=1;
      }

    for(auto it : adj[i])
    {
        if(!vis[it])
        {
            if(dfs(it,adj,dfsvis,vis))return true;
        }
        else if(dfsvis[it]) return true;
        
    }
      dfsvis[i]=0;
    return false; 
    
}
bool iscyclic(vector<int>v[],int n)
{
     vector<int>vis(n+1,0);
     vector<int>dfsvis(n+1,0);

     for(int i=0;i<n;i++)
     {
        if(!vis[i])
            if(dfs(i,v,dfsvis,vis))return true;
     }
     return false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>v[n+1];

    for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
        }

    if(iscyclic(v,n))
        cout<<"True";
    else cout<<"False";
}

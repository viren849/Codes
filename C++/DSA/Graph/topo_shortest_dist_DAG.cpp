//Shortest Distance to reach to all other nodes ..
//IN DAG USING TOPOSORT......

#include<bits/stdc++.h>
using namespace std;
 
  void dfstopo(vector<pair<int,int>>adj[],stack<int>&st,int n,vector<int>&vis)
  {
          vis[n]=1;

          for(auto it : adj[n])
             if(!vis[it.first])
                dfstopo(adj,st,it.first,vis);

          st.push(n);
  }
int main()
{
    int n,m;
    cin>>n>>m;

    vector<pair<int,int>>v[n];

    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        v[x].push_back({y,w});
    }

    int src;
    cin>>src;
   
    vector<int>dist(n,INT_MAX);
    
    dist[src]=0;

    //APPLYING TOPOSORT.....

    stack<int>st;
    vector<int>vis(n,0);
     for(int i=0;i<n;i++)
     {
        if(!vis[i])
         dfstopo(v,st,i,vis);
     }

    while(!st.empty())
    {
        int t=st.top();
        st.pop();
    if(dist[t]!=INT_MAX)
       for(auto it:v[t])
        {
            dist[it.first]=min(dist[it.first],dist[t]+it.second);
        }
    }
    for(int i : dist)
        cout<<i<<" ";
}

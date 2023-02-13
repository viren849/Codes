#include<bits/stdc++.h>
using namespace std;

void topodfs(int n,vector<int>adj[],vector<int>&vis,stack<int>&st)
{
       vis[n]=1;
       for(auto it : adj[n])
          if(!vis[it])
           topodfs(it,adj,vis,st);
     // cout<<n<<" ";
      st.push(n);
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
        stack<int>st;
   vector<int>vis(n+1,0);
   for(int i=0;i<=n;i++)
     {
        if(!vis[i])
          topodfs(i,v,vis,st);
     }

    while(!st.empty())
    {
        cout<<st.top()<<",";
          st.pop();
    }
}

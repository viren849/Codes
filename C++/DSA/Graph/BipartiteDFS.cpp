#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>&col,vector<int>adj[],int node)
{

       if(col[node]==-1)
        col[node]=1;
      
     for(int it:adj[node])
        {
            if(col[it]==-1)
            {
              col[it]=1-col[node];
              if(!dfs(col,adj,it))return false;
            }
            else if(col[it]==col[node])return false;
        }
        return true;
}
bool isbipartite(vector<int> adj[],int n)
{
   vector<int>col(n+1,-1);

   for(int i=1;i<=n;i++)
     {
        if(col[i]==-1)
        {
            if(!dfs(col,adj,i))return false;
        }
     }
     return true;
}
int main()
{
  int n,e;

  cin>>n>>e;

   vector<int>adj[n+1];

     for(int i=0;i<e;i++)
     {
      int x,y;

        cin>>x>>y;
         
       adj[x].push_back(y);
       adj[y].push_back(x);
     }

     cout<<isbipartite(adj,n);
}
//Shortest Distance to reach to all other nodes ..
//in a unweighted and undirected nodes ...

#include<bits/stdc++.h>
using namespace std;

void dfs(int n,vector<int>adj[],vector<int>&dist)
{

    for(int it : adj[n])
    {
         if(dist[n]+1 < dist[it])
         {
            dist[it]=1+dist[n];
            dfs(it,adj,dist);
         }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];

    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int src;
    cin>>src;
    
    vector<int>dist(n,INT_MAX);

    dist[src]=0;

    //applying DFS....

    for(int i = 0; i<n;i++)
    {
          dfs(i,adj,dist);
    }

    for(int i : dist)
    {
        cout<<i<<" ";
    }

}

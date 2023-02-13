//Shortest Distance to reach to all other nodes ..
//in a unweighted and undirected nodes ...

#include<bits/stdc++.h>
using namespace std;

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

    //applying BFS....

    queue<int>q;

      q.push(src);

    while(!q.empty())
    {
        int t=q.front();
         q.pop();

         for(int it : adj[t])
         {
            if(dist[t]+1 < dist[it])
            {                            //if i use dist[it]=min(dist[it],dist[t]+1)
                dist[it]=dist[t]+1;      //can be done by taking vis arry....
                q.push(it);
            }
         }
    }

    for(int i : dist)
    {
        cout<<i<<" ";
    }

}

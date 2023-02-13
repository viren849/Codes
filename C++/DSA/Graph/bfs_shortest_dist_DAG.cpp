
//shortest distance in DAG , weighted.. 
//USING BFS....
#include<bits/stdc++.h>
using namespace std;


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

    //APPLYING BFS.....

    dist[src]=0;

    queue<int>q;
    q.push(src);

    while(!q.empty())
    {
        int t=q.front();
         q.pop();

         for(auto it:v[t])
         {
            if(dist[t]+it.second < dist[it.first])
            {
                dist[it.first]=dist[t]+it.second;
                q.push(it.first);
            }
         }
    }

    for(int i : dist)
         cout<<i<<" ";
    // cout<<floor(3.0/2);
}

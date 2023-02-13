#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
 
  bool bfs(vector<int>&vis,vector<int>arr[],int node)
 {
       queue<pair<int,int>>q;
       q.push(node,-1);
       vis[node]=1;
       while(!q.empty())
       {  
           int front=q.front().first;
           int prev=q.front().second;
           q.pop();
           for(int it:arr[front])
           {
                 if(!vis[it])
                 {
                   vis[it]=1;
                   q.push(it,front);
                 }
                 else if(prev!=it) return true;
           }
       }

       return false;
 }
 bool dfs(vector<int>&vis,vector<int>arr[],int node,int par)
 {

       vis[i]=1;

       for(int i : arr[node])
         {
           
             if(!vis[i])
             {
                 if(dfs(vis,arr,i,node))return true;
             }
             else if(i!=par)return true;
         }
     return false;
 }
void solve()
{

     int n,e;
     cin>>n>>e;
     vector<int>arr[n+1];
     for(int i=0;i<e;i++)
       {
          int x,y;
          cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
       }    
       vector<int>vis(n+1,0);

    //DFS..............
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
          if(dfs(vis,arr,i,-1))
          {
            cout<<"yes";
             break;
          }
    }
  //BFS.................

    for(int i=1;i<=n;i++)
    {
        if(!vis)
        {
            bfs(vis,arr,i,-1);
        }
    }

}

int main()
{
  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
#include<iostream>
#include<vector>
using namespace std;

int n=1e5,m;
vector<int>g[n];
vector<int>vis(n,0);
bool path(int cur,int cnt)
{
     
     if(cnt == n)
      return true;

     vis[cur]=1;

     for(int it : g[cur])
     {
         if(!vis[it])
          if(path(it,cnt+1))
            return true;
     }
     vis[cur]=0;
    return false;
}
int main()
{
  cin>>n>>m;

  for(int i=0;i<m;i++)
  {
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
   for(int i=0;i<n;i++)
       path(i,1);
}
#include<bits/stdc++.h>
using namespace std;

bool  bipartite_func(arr,v,i)
{

      queue<int>q;
      q.push(i);
      
      arr[i]=0;
   while(!q.empty())
    { 
         int node=q.front();
         q.pop();

         for(int it : v[node])
         {
              if(arr[it]==-1)
              {
                arr[it]=1-arr[node];
                q.push(it);
              }
              else
                if(arr[it]==arr[node])
                  return false;
              
         }
      }
      return true;
}
   
   bool check_Bipartite()
   {


         for(int i=0;i<n;i++)
           {
               if(arr[i]==-1)
                  if(bipartite_func() == 0)return false;
           }
           return true;
   }
int main()
{
  
    int n,e;
    cin>>n>>e;

    vector<int>v[n+1];

    for(int i=0;i<e;i++)
       {
          cin>>x>>y;
          v[x].push_back(y);
          v[y].push_back(x);
       }
   
   vector<int>color_arr(n+1,-1);
}
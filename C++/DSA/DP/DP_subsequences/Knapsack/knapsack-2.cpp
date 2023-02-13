// knapsack -2 

#include<bits/stdc++.h>
using namespace std;
int val[105];
int wt[105];
int dp[105][100005];

long long func(int n,int vl)
{
     if(vl == 0 )
        return 0;
     if(n < 0)return 1e11 ;
     
     if(dp[n][vl]!=-1)return dp[n][vl];
     long long l=1e11,r;

     r=func(n-1,vl);

     if(vl-val[n] >=0)
        l=wt[n]+func(n-1,vl-val[n]);

   return dp[n][vl]=min(l,r);
}
int main()
{
  int n,W;
  cin>>n>>W;

  memset(dp,-1,sizeof(dp));

  for(int i=0;i<n;i++)
    cin>>wt[i]>>val[i];
   int mx=1e5;
  for(int i=mx;i>=0;--i)
  {
       int ans=func(n-1,i);
       if(ans <= W)
        {
          cout<<i;break;
        }
  }
   return 0;
}
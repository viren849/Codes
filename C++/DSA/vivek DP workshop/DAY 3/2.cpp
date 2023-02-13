#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back


int n,m;
int mat[1010][1010];
int dp[1010][1010];
int mod=1000000007;
int rec(int i,int j)
{
    if(i<0 || j<0 || mat[i][j]==1) return 0;
    if(i==0 && j==0) return 1;
    
    if(dp[i][j]!=-1) return dp[i][j];
    
     int ans = 0;
     ans+=rec(i-1,j)%mod;
     ans+=rec(i,j-1)%mod;
    
    return dp[i][j] = ans%mod;
}
void solve()
{
  cin>>n>>m;
   
   
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>mat[i][j];
        dp[i][j]=-1;
    }
    
    
    cout<<rec(n-1,m-1)%mod<<endl;
}

signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t;
  cin>>t;
    while(t--)
    {
      solve();
    }
}
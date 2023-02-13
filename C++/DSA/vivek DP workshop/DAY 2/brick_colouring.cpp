#include<bits/stdc++.h>
using namespace std;

#define int               long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
const int mod=1e9+7;

int dp[2001][2001];
int m;
int func(int n,int k)
{
    if(n==1)
    {
      if(k==0)return m;
      return 0;
    }

    if(dp[n][k] != -1)return dp[n][k];

    int ans=func(n-1,k)%mod;
    ans+=(m-1)*func(n-1,k-1)%mod;

    return dp[n][k]=ans%mod;
}
void solve()
{
   int n,k;
   cin>>n>>m>>k;

   memset(dp,-1,sizeof(dp));
   cout<<func(n,k);
}

signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
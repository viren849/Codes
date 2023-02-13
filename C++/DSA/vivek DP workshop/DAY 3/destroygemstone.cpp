#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int a[101];
int dp[105][105];
int func(int l,int r)
{
    if(l>=r)return 1;

    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1e18;

    if(a[l]==a[r])
      ans=func(l+1,r-1);

    for(int m=l;m<=r-1;m++)
      ans=min(ans,func(l,m)+func(m+1,r));

    return dp[l][r]=ans;
}
void solve()
{
   int n;
   cin>>n;

   for(int i=0;i<n;i++)
        cin>>a[i];

   for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j]=-1;

    cout<<func(0,n-1);
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
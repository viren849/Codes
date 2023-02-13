#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int arr[501];
int dp[505][505];
int func(int l,int r)
{
    if(l>=r)return 0;

    if(dp[l][r]!=-1)
      return dp[l][r];

    int ans=1e9;
    int tot=0;
    for(int i=l;i<=r;i++)
      tot+=arr[i];
   int sum =0;
    for(int m=l;m<r;m++)
    {
      sum+=arr[m];
      ans=min(ans,func(l,m)+func(m+1,r) + (sum%100)*((tot-sum)%100));
    }
    return dp[l][r]=ans;
}
void solve()
{
   int n;
   cin>>n;

   for(int i=0;i<n;i++)
        cin>>arr[i];

   for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
      dp[i][j]=-1;

    cout<<func(0,n-1);
}

signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  //cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
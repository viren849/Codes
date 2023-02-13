#include<bits/stdc++.h>
using namespace std;

#define int             long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int mat[1010][1010];
int dp[1010][1010];

int rec(int i,int j)
{
    if(i<0 || j<0) return 0;
    if(i==0 && j==0) return mat[i][j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    ans+=max(rec(i-1,j),rec(i,j-1))+mat[i][j];

    return dp[i][j] = ans;
}
void solve()
{
  int n,m;
  cin>>n>>m;
   
    memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    {
        cin>>mat[i][j];
    }
    
    cout<<rec(n-1,m-1)<<endl;
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
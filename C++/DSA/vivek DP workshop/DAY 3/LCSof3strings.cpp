#include<bits/stdc++.h>
using namespace std;

#define int               long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
const int mod=1e9+7;

int dp[101][101][101];
string a,b,c;

int func(int i,int j ,int k)
{

    if(i == 0 || j== 0 || k==0)
      return 0;

     if(dp[i][j][k]!=-1)
      return dp[i][j][k];

    if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
      return 1+func(i-1,j-1,k-1);

    int ans=0;

    ans=max(ans,func(i-1,j,k));
    ans=max(ans,func(i,j-1,k));
    ans=max(ans,func(i,j,k-1));
    return dp[i][j][k]=ans;

}
void solve()
{
  cin>>a>>b>>c;
  memset(dp,-1,sizeof(dp));
  cout<<func(a.size(),b.size(),c.size());
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
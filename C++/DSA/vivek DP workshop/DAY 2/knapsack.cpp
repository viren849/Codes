#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
vector<int>wi,vi;
int dp[21][101];
int func(int n,int w)
{
  if(n < 0)
    return 0;
  if(dp[n][w]!=-1)
    return dp[n][w];

  int l=func(n-1,w);
  int r=0;
  if(w-wi[n] >=0)
   r=vi[n]+func(n-1,w-wi[n]);
  return dp[n][w]=max(l,r);
}
void solve()
{
  int n,w;
  cin>>n>>w;
  int t=n;
  memset(dp,-1,sizeof(dp));
  while(t--)
  {
    int x,y;
    cin>>x>>y;
    wi.pb(x);
    vi.pb(y);
  }

  cout<<func(n-1,w);
}

int main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
 // cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
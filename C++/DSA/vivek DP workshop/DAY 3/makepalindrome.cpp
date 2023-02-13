#include<bits/stdc++.h>
using namespace std;

#define int               long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
const int mod=1e9+7;

int dp[1001][1001];
string a,b;

int func(int i,int j)
{

    if(i == 0 || j== 0)
      return 0;

     if(dp[i][j]!=-1)
      return dp[i][j];

   
    if(a[i-1]==b[j-1])
      return 1+func(i-1,j-1);
  
    
    return dp[i][j]=max(func(i-1,j),func(i,j-1));

}
void solve()
{
  cin>>a;
  b=a;
  reverse(b.begin(),b.end());
  memset(dp,-1,sizeof(dp));
  int ans=func(a.size(),a.size());
    
  cout<<a.size()-ans;
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
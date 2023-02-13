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

    int ans=0;
    if(a[i-1]==b[j-1])
      ans=max(ans,1+func(i-1,j-1));
    func(i-1,j),func(i,j-1);
    
    return dp[i][j]=ans;

}
void solve()
{
  cin>>a>>b;
  memset(dp,-1,sizeof(dp));
  int ans=0;
    for (int i=1;i<=a.size();i++){
        for (int j=1;j<=b.size();j++){
            ans=max(ans,func(i,j));
        }
    }
    cout<<ans;
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
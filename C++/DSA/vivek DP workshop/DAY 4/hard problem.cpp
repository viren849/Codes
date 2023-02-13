#include<bits/stdc++.h>
using namespace std;

#define int             long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
vector<int>arr;
string s;
int dp[100001][5];
string m="hard";

int func(int level,int match)
{
      if(match == 4)
        return 1e18;
      if(level == n)
        return 0;
      if(dp[level][match]!=-1)
        return dp[level][match];

      int ans=1e18;
      if(s[level]!=m[match])
        ans=min(ans,func(level+1,match));
      else 
        ans=min(func(level+1,match+1),arr[level]+func(level+1,match));
     return dp[level][match]=ans;
   }

void solve()
{
    cin>>n;
    cin>>s;
    arr.resize(n,0);
    for(int i=0;i<n;i++)
      cin>>arr[i];
    
    for(int i=0;i<n;i++)
      for(int j=0;j<5;j++)
        dp[i][j]=-1;

    cout<<func(0,0);
}

signed main()
{
  fast;
  int t;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
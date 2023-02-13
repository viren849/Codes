#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int dp[200001];
int func(int x)
{
    if(x==0)
      return 0;
    if(dp[x]!=-1)
      return dp[x];
    int ans=0;
    for(int i=0;(1<<i)<=x;i++)
    {
        if(func(x-(1<<i)) == 0)
        {
          ans=1;
          break;
        }
    }
    return dp[x]=ans;
}
void solve()
{
   int x;
   cin>>x;

   memset(dp,-1,sizeof(dp));
   if(func(x)==0)
     cout<<"Abhishek";
   else cout<<"Vivek";
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
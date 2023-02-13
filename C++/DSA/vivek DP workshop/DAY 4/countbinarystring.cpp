
//No. of binary  string which doesnot have 0100 as a substring....
#include<bits/stdc++.h>
using namespace std;

#define int             long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 
#define fast   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
const int md=1e9+7;
int dp[1000001][5];
int func(int level,int state)
{
      if(state == 4)return 0;
      if(level == 0)
        return 1;
    
      if(dp[level][state]!=-1)
        return dp[level][state];

      int ans=0;

      if(state==0)
        ans=func(level-1,1)%md+func(level-1,0)%md;
      else if(state==1)
        ans=func(level-1,2)%md+func(level-1,1)%md;
        else if(state == 2)
          ans=func(level-1,3)%md+func(level-1,0)%md;
          else if(state ==3)
           ans=func(level-1,4)%md+func(level-1,2)%md;

    return dp[level][state]=ans%md;
}
void solve()
{
      cin>>n;
      
      // for(int i=0;i<n;i++)
      //   for(int j=0;j<5;j++)
      //     dp[i][j]=-1;

     cout<<func(n,0)%md; 
}
signed main()
{
  
  fast;   
  memset(dp,-1,sizeof(dp));
  int t=1;  
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}
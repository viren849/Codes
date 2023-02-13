
//using form 2 i.e best ending at i and j 
#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

int mat[1001][1001];
int dp[1001][1001];

int func(int n,int m)
{
    if(n < 0 || m < 0 || mat[n][m] == 0) return 0;
    
    if(n==0 && m==0) return mat[0][0]==1;

    int up=func(n-1,m);
    int d=func(n-1,m-1);
    int left=func(n,m-1);
    return 1+min({up,left,d});
}
void solve()
{
  int n,m;
  cin>>n>>m;

  for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>mat[i][j];

   int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) {
                ans = max(ans, func(i, j));
            }
        }
    }
   cout<<ans*ans; // 0 based indexing...
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
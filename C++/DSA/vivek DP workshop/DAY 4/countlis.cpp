

#include<bits/stdc++.h>
using namespace std;

#define int              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 


void solve()
{
      int n;
      cin>>n;
      int arr[n];

      for(int i=0;i<n;i++)
        cin>>arr[i];

      int maxi=INT_MIN;
      
      vector<int> cnt(n+1),dp(n+1);

      for(int i=0;i<n;i++)
      {
        cnt[i]=1;
        int ans=1;
        for(int j=0;j<i;j++)
        {
          if(arr[j] < arr[i])
            {
                      if(ans < dp[j]+1)ans=dp[j]+1,cnt[i]=cnt[j];
                    else if(ans==dp[j]+1)
                        cnt[i]+=cnt[j]; 
            } 
        }
        // cout<<i<<"->";
        // for(int i1=0;i1<n;i1++)
        //   cout<<dp[i1]<<" ";
        // cout<<endl;
        dp[i]=ans;
        maxi=max(dp[i],maxi);
      }
    
    int cntlis=0;
    for(int i=0;i<n;i++)
      if(maxi == dp[i])
        cntlis+=cnt[i];
    cout<<cntlis;
}
signed main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

  int t=1;
  cin>>t;
    while(t--)
    {
      solve();
      cout<<endl;
    }
}

//DP on Subsequences ...
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

    vector<vector<int>>dp;
    bool func(vector<int>&arr,int n,int tar)
{
    

      if(tar == 0)
        return true;
      if(n == 0)
        return arr[0] == tar ;
        
          if(dp[n][tar]!=-1)
           return dp[n][tar];
        
      bool not_take=func(arr,n-1,tar);
      bool take=false;

      if(tar >=arr[n])
        take=func(arr,n-1,tar-arr[n]);

      return dp[n][tar]=not_take or take;
}

    
bool functab(vector<int>&arr,int n ,int tar)
{
    for(int i=0;i<=n;i++)
      for(int j=0;j<=tar;j++)
      {
            if(j==0) dp[i][j]=1;
            else if(i == 0)dp[i][j]=(arr[i]==j);
            else
            {
              bool not_take=dp[i-1][j];
              bool take=false;

              if(j >=arr[i])
                take=dp[i-1][j-arr[i]];

              dp[i][j]=not_take or take;
            }

      }
      return dp[n][tar];
}

bool spaceopti(int tar,int arr[],int n)
{
  vector<int>cur(tar+1,0);
  vector<int>prev(tar+1,0);

  for(int i=0;i<=n;i++)
     {

      for(int j=0;j<=tar;j++)
      {
            if(j==0) cur[j]=1;
            else if(i == 0)cur[j]=(arr[i]==j);
            else
            {
              bool not_take=prev[j];
              bool take=false;

              if(j >=arr[i])
                take=prev[j-arr[i]];

              cur[j]=not_take or take;
            }
       prev=cur;
      }
      return cur[tar];
}


void solve()
{ 
    int n;
    cin>>n;
    
    int arr[n];

    for(int i=0;i<n;i++)
      cin>>arr[i];
    int tar;
    cin>>tar;
}

int main()
{
  
   ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
   
        solve();
        cout<<endl;
}
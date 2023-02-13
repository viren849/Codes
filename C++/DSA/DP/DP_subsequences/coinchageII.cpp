  
//coin  change problem
//Two Variation in which one is to find min coin and 
//other is all the way.....


//striver.....
int func(int n ,int amt,vector<int>&coins)
    {
        if(amt == 0 )
            return 1;
        
         if(n == 0) return 0;
        
        if(dp[n][amt]!=-1)
            return dp[n][amt];
        
        int nt=func(n-1,amt,coins);
        int t=0;
        if(amt >= coins[n-1])
            t=func(n,amt-coins[n-1],coins);
         return dp[n][amt]=t+nt;   
    }

int tab1(int n ,int amt,vector<int>&coins)
{
        int dp[n+1][amt+1];

        for(int i=0;i<=n;i++)
          for(int j=0;j<=amt;j++)
             {
                  if(j==0)dp[i][j]=1;
                  else if(i==0)dp[i][j]=0;
                  else
                  {
                    int nt=dp[i-1][j];
                    int t=0;
                    if(j>=coins[i-1])
                       t=dp[i][j-coins[i-1]];
                       dp[i][j]=t+nt;
                  }
             }
             return dp[n][amt];
}
int tab2(int n ,int amt,vector<int>&coins)
    {
        int dp[n][amt+1];

        for(int i=0;i<n;i++)
          for(int j=0;j<=amt;j++)
             {
                  if(j==0)dp[i][j]=1;
                 else if(i==0)dp[i][j]=(j%coins[i])==0;
                  else
                  {
                    int nt=dp[i-1][j];
                    int t=0;
                    if(j>=coins[i])
                       t=dp[i][j-coins[i]];
                     dp[i][j]=t+nt;
                  }
             }
             return dp[n-1][amt]; 
    }

int spacepti()
{

   vector<int>prev(amt+1,0);
   vector<int>cur(amt+1,0);

        for(int i=0;i<n;i++)
          {
            for(int j=0;j<=amt;j++)
             {
                  if(j==0)cur[j]=1;
                 else if(i==0)cur[j]=(j%coins[i])==0;
                  else
                  {
                    int nt=prev[j];
                    int t=0;
                    if(j>=coins[i])
                       t=cur[j-coins[i]];
                     cur[j]=t+nt;
                  }
             }
             prev=cur;
           }
             return prev[amt]; 
}
#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


//in the below code duplicate will be counted eg:
// 1 1 1 2
//1 2 1 1  ,   1 1 2 1,  these all are one but will be counted as 3 this approach
// is wrong then.....
//LUV...
int all_way_coin(vector<int>&coins,int amt)
{
    if(amt==0)return 1;
    if(amt<0)return 0;
    int ans=0;
    for(int coin:coins)
      if(amt-coin>=0)
         ans=ans+all_way_coin(coins,amt-coin);
    return ans;
}

//then the new index concept will come...

int all_way_coin2(int index,vector<int>&coins,int amt)
{
    if(amt==0)return 1;


    int ans=0;
//i ndex ke pahle saree coin khtm krlo .....
  for(int i=index;i<coins.size();i++)
      if(amt-coins[i]>=0)
         ans=ans+all_way_coin2(i,coins,amt-coins[i]);
    return ans;
}

//we can take repeatedly.......

int all_way_coin3(int i,vector<int>&coins,int amt)
{
        if(amt == 0)return 1;

        int l=0,r=0;

        if(amt-coins[i] >=0)
        l=all_way_coin3(i,coins,amt-coins[i]);

      if(i+1 < coins.size())
        r=all_way_coin3(i+1,coins,amt);
      return l+r;
}
int main()
{
  int n;
  cin>>n;
  vector<int>coins(n);

  for(int i=0;i<n;i++)
     cin>>coins[i];
   int amt;
   cin >> amt;

   cout<<all_way_coin3(0,coins,amt);
}
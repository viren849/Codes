
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

//min insertion to make string palindrome...

class Solution {
public:
    int dp[501][501];
    
    int func(string &s,int i,int j)
    {
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=2+func(s,i+1,j-1);
        return dp[i][j]=max(func(s,i+1,j),func(s,i,j-1));
    }
    int minInsertions(string s) {
        int n=s.size();
       memset(dp,-1,sizeof(dp));
      int res=func(s,0,n-1);
       // cout<<res;
          return n-res;
    }
};

//tabulation  
 int func(string &s,int i1,int j1)
    {
       int n=s.size();    
         for(int i=n-1;i>=0;i--)
         {
             for(int j=0;j<n;j++)
             {
                 if(i>j)dp[i][j]=0;
                 else if(i==j)dp[i][j]=1;
                 else
                 {
                     if(s[i]==s[j])
                         dp[i][j]=2+dp[i+1][j-1];
                     else
                         dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                 }
             }
         }
         return dp[0][n-1];
    }

 int spacefunc(string &s,int i1,int j1)
    {
       int n=s.size();  
         vector<int>cur(n),next(n);
         for(int i=n-1;i>=0;i--)
         {
             for(int j=0;j<n;j++)
             {
                 if(i>j)cur[j]=0;
                 else if(i==j)cur[j]=1;
                 else
                 {
                     if(s[i]==s[j])
                         cur[j]=2+next[j-1];
                     else
                         cur[j]=max(next[j],cur[j-1]);
                 }
             }
             next=cur;
         }
         return cur[n-1];
    }
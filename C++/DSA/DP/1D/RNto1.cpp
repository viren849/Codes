//REDUCE N->1 BY n-1,n/2,n/3;
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int helper(int n)
{
  if(n==1)
    return 0;
  int a=INT_MAX,b=INT_MAX,c=INT_MAX;
  
   if(n%3 == 0)
     a=helper(n/3);
   if(n%2 == 0)
      b=helper(n/2);

   c=helper(n-1);

   return min(a,min(b,c))+1;
}
int tab(int n)
{
    vector<int>dp(n+1);
    dp[1]=0;
    dp[2]=dp[3]=1;
    for(int i=4;i<n;i++)
    {
      int a,b,c;
      a=b=c=INT_MAX;
      if(i%3==0)
      a=dp[i/3];
      if(i%2==0)
      b=dp[i/2];

      c=dp[i-1];
      dp[i]=1+min(a,min(b,c));
    }
    // for(int i : dp)
    //   cout<<i<<" ";
    // cout<<endl;
    return dp[n-1];
}
int main()
{
  int n;
  cin>>n;

  cout<<helper(n);
}
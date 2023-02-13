#include<iostream>
                           
using namespace std;

int stair(int n)
{

  if(n==1)return 1;

  int l=0,r=0;
   l+=stair(n-1);//either one step 
   r+=stair(n-2);// or two step..
  return l+r;
}

int dp[1001]={-1};
int memostair(int n)
{

  if(n<=1)return 1;
  
  if(dp[n]!=-1) return dp[n];

  int l=0,r=0;
   l+=stair(n-1);//either one step 
   r+=stair(n-2);// or two step..

  return dp[n]=l+r;
}

int dp[1001];

int tabstair(int n)
{
       dp[1]=1;
      for(int i=2;i<=n;i++)
      {
          
        dp[i]=dp[i-1]+dp[i-2];
      }
      return dp[n];
}
int spaceopti(int n){

    int a=1,b=1;

    for(int i=2;i<n;i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{

  int n;
  cin>>n;

  int res=stair(n);
  cout<<res;
  
}
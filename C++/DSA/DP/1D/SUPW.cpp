#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int helper(vector<int>&arr,int n)
{
  if(n<3)return arr[n];
  
     if(n==3)
      return min(arr[n-1],min(arr[n-2],arr[n-3]));
     
  return arr[n-1]+min(helper(arr,n-1),min(helper(arr,n-2),helper(arr,n-3)));
}
int tab(vector<int>&arr,int n)
{
    vector<int>dp(n+1,0);

    for(int i=0;i<3;i++)
       dp[i]=arr[i];

     for(int i=3;i<n;i++)
      dp[i]=arr[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));

    return min(dp[n-1],min(dp[n-2],dp[n-3]));
}
int spaceopti(vector<int>&arr,int n)
{
  int a=arr[0];
  int b=arr[1];
  int c=arr[2];
  int res=0;
  for(int i=3;i<n;i++)
  {
        res=arr[i]+min(a,min(b,c));
        a=b;
        b=c;
        c=res;
  }
  
     return min(a,min(b,c));
  }
int main(){
      
      int n;
      cin>>n;
      vector<int>arr(n);

      for(int i=0;i<n;i++)
         cin>>arr[i];
      cout<<helper(arr,n);
  }
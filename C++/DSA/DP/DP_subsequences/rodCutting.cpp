#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
using ll=long long;
vector<int>arr;

int  helper1(int ind,int len)
{
     if(ind == 0 || len==0)
        return 0;

      int nt=helper1(ind-1,len);
      int t=INT_MIN;

     if(ind<=len)
       t=arr[ind-1]+helper1(ind,len-ind);

     return max(t,nt);
}
int tabhelper1(int ind,int len)
{
     int dp[ind+1][len+1];

     for(int i=0;i<=ind;i++)
      for(int j=0;j<=len;j++)
      {
             if(i==0 || j==0)
                dp[i][j]=0; 
              else
              {
                int t=INT_MIN;
                if(i<=j)
                  t=arr[i-1]+dp[i][j-i];
                dp[i][j]=max(dp[i-1][j],t);
              }
      }
      return dp[ind][len];
}
int spaceopthelper1(int ind,int len)
{
  
    vector<int>cur(len+1,0);
    vector<int>prev(len+1,0);

     for(int i=0;i<=ind;i++)
      for(int j=0;j<=len;j++)
      {
             if(i==0 || j==0)
               cur[j]=0; 
              else
              {
                int t=INT_MIN;
                if(i<=j)
                  t=arr[i-1]+cur[j-i];
                cur[j]=max(prev[j],t);
              }
              prev=cur;
      }
      return cur[len];
}

//unbounded knapsack can be reduced to one -d array .....

int oneDarr(int ind,int len)
{
  
    vector<int>prev(len+1,0);

     for(int i=0;i<=ind;i++)
      for(int j=0;j<=len;j++)
      {
             if(i==0 || j==0)
               prev[j]=0; 
              else
              {
                int t=INT_MIN;
                if(i<=j)
                  t=arr[i-1]+prev[j-i];
               prev[j]=max(prev[j],t);
              }
              
      }
      return prev[len];
}
int helper2(int n)
{
   if(n==0)
    return 0;

   int ans=INT_MIN;
      for(int i=1;i<=n;i++)
      {
           ans=max(ans,arr[i-1]+helper2(n-i));
      }
      return ans;
}

int main()
{
    int n;
    cin>>n;
    arr.resize(n);  

    for(int i=0;i<n;i++)
      cin>>arr[i];
   cout<<tabhelper1(n,n);
}
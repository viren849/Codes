#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
using ll=long long;

vector<int>arr;
vector<int>wt;

int helper1(int n,int W)
{
      if(n==0 || W == 0)   //if(n==1)
        return 0;          // return (w/wt[0])*val[0];

      int nt=helper1(n-1,W);
      int t=INT_MIN;

      if(wt[n-1]<=W)
        t=arr[n-1]+helper1(n,W-wt[n-1]);

      return max(t,nt);
}
int tabhelper1(int n,int W)
{
       int dp[n+1][W+1];
         for(int i=0;i<=n;i++)
            for(int j=0;j<=W;j++)
            {
                if(i==0 || W==0)
                  dp[i][j]=0;
                else
                {
                  int t=INT_MIN;
                  if(wt[i-1]<=j)
                    t=arr[i-1]+dp[i][j-wt[i-1]];
                  dp[i][j]=max(t,dp[i-1][j]);
                }
            }
        return dp[n][W];
}
int spaceoptihelper1(int n,int W)
{
    vector<int>cur(W+1,0);
    vector<int>prev(W+1,0);

         for(int i=0;i<=n;i++)
         {
            for(int j=0;j<=W;j++)
            {
                if(i==0 || W==0)
                  cur[j]=0;
                else
                {
                  int t=INT_MIN;
                  if(wt[i-1]<=j)
                    t=arr[i-1]+cur[j-wt[i-1]];
                  cur[j]=max(t,prev[j]);
                }
            }
            prev=cur;
          }
        return prev[W];
}
int spaceoptihelper1Darr(int n,int W)
{
    
    vector<int>prev(W+1,0);

         for(int i=0;i<=n;i++)
         {
            for(int j=0;j<=W;j++)
            {
                if(i==0 || W==0)
                  prev[j]=0;
                else
                {
                  int t=INT_MIN;
                  if(wt[i-1]<=j)
                    t=arr[i-1]+prev[j-wt[i-1]];
                  prev[j]=max(t,prev[j]);
                }
            }
            
          }
        return prev[W];
}
int main(){

    int n;
    int W;
    cin>>n>>W;

    arr.resize(n);
    wt.resize(n);

    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int i=0;i<n;i++)
      cin>>wt[i];

    cout<<spaceoptihelper1Darr(n,W);

}
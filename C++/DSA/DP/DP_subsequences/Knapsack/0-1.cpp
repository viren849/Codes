#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;


int knapsack(int n,int weight[],int values[],int W)
{
      if(n==0 || W==0)
        return 0;

      if(weight[n-1]<=W)
       {
        //backtracking...
          // W-=weight[n-1];
          // int x=values[n-1]+knapsack(n-1,weight,values,W);
          // W+=weight[n-1];

        int x=values[n-1]+knapsack(n-1,weight,values,W-weight[n-1]);//not backtracking

        int y=knapsack(n-1,weight,values,W);
        return max(x,y);
      }
          
      else 
        return knapsack(n-1,weight,values,W);
}


//MEMOIZATION>>>>>>

int dp[100][100];//n,W

int memoknapsack(int n,int weight[],int values[],int W)
{
      if(n==0 || W==0)
        return 0;
      
      if(dp[n][W]!=-1)
        return dp[n][W];

      if(weight[n-1]<=W)
       {
        //backtracking...
          // W-=weight[n-1];
          // int x=values[n-1]+memoknapsack(n-1,weight,values,W);
          // W+=weight[n-1];

        int x=values[n-1]+memoknapsack(n-1,weight,values,W-weight[n-1]);//not backtracking

        int y=memoknapsack(n-1,weight,values,W);
        return dp[n][W]= max(x,y);
      }
          
      else 
        return dp[n][W]= memoknapsack(n-1,weight,values,W);
}

//TABULATION()

int knapsack(int n,int weight[],int values[],int W)
{
       for(int i=0;i<=n;i++)
        for(int j=0;j<=W;j++)
        {
          if(i==0||j==0)
            dp[i][j]=0;
         else if(weight[i-1]>j)
            dp[i][j]=dp[i-1][j];
          else
            dp[i][j]=max(values[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
        }
        return dp[n][W];
}

int spaceopti(int n,int weight[],int values[],int W)
{

   vector<int>cur(W+1,0);
  vector<int>prev(W+1,0);

  for(int i=0;i<=n;i++)
      {
        for(int j=0;j<=W;j++)
        {
          if(i==0||j==0)
            cur[j]=0;
         else if(weight[i-1]>j)
            cur[j]=prev[j];
          else
            cur[j]=max(values[i-1]+prev[j-weight[i-1]],prev[j]);
        }
        prev=cur;
      }
        return prev[W];
}

//one array space opti ....
//fill the arrray in backward if u se the tabulation carefully....
int opti(int n,int weight[],int values[],int W)
{
     vector<int>cur(W+1,0);

     for(int i=0;i<=n;i++)
      for(int j=W;j>=0;j--)
         {
              if(i==0||j==0)
                cur[j]=0;
              else if(weight[i-1] > j)
                cur[j]=cur[j];
              else
                cur[j]=max(values[i-1]+cur[j-weight[i-1]],cur[j]);
         }
}
int main()
{
  int n;
  cin>>n;
 // memset(dp,-1,sizeof(dp));
  int values[n];
  int weight[n];
  int W;

  for(int i=0;i<n;i++)
    cin>>values[i];
  for(int i=0;i<n;i++)
    cin>>weight[i];

  cin>>W;

  cout<<knapsack(n,weight,values,W);
  return 0;
}
#include<iostream>
#include<vector>
using namespace std; 

int main()
{
     int n;
     cin >> n;
     int dp[n+1][n+1];
     

     dp[0][0]=1;
     dp[1][0]=dp[1][1]=1;

     for(int i=2;i<n;i++)
     {   
        dp[i][0]=dp[i][i]=1;

         for(int j=1;j<i;j++)
            dp[i][j]=dp[i-1][i-(j+1)]+dp[i-1][i-j];
     }

     for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
    }
}
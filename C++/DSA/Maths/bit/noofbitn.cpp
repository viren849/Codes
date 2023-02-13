#include<iostream>
#include<vector>
using namespace std;

  
int main(){

  int n;

  vector<int>dp(n+1,0);

    for(int i=1;i<=n;i++)
    {
          dp[i]=dp[i/2]+(i%2);
    }
    for(int i:dp)
      cout<<i<<" ";
}
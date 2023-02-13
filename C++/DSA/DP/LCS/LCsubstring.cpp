#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//Longest Common Substring....
 
 string s1,s2;

int main()
{
  
  cin>>s1>>s2;
int i1,j1;
    int n=s1.length();
    int m=s2.length();

    
    
    int dp[n][m];
    int mx=INT_MIN;
  for(int i=0;i<=n;i++)
    for(int j=0;j<=m;j++)
    {
          if(i==0 || j==0)
            dp[i][j]=0;
          else
            if(s1[i-1]==s2[j-1])
              dp[i][j]=1+dp[i-1][j-1];
            else
              dp[i][j]=0;
        if(mx<dp[i][j])
        {
          i1=i;j1=j;
          mx=dp[i][j];
        }
    }

    //printing the lcs....

    int ln=mx;
    cout<<mx<<"\n";

    int i=i1,j=j1;
     char s[ln+1];
     s[ln]='\0';
    while(i>0 && j>0)
    {
          
            s[ln-1]=s1[i-1];
            ln--;
            i--;j--;
          
    }
      cout<<s;
}
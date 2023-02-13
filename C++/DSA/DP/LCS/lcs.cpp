
//LCS
//follow up 
//LPS(longest palindromic subsequences)(can be do s1=s and s2=s.reverse())
//no. of insertion to make string palindrome (n- LPS(s));

#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
using ll=long long;

string s1;
string s2;
int LCS(int i,int j){
    
    if(i==0||j==0)
      return 0;
    if(s1[i-1]==s2[j-1])
      return 1+LCS(i-1,j-1);
    
    return max(LCS(i,j-1),LCS(i-1,j));
}

int tablcs(int n,int m)
{
  int dp[n+1][m+1];

     for(int i=0;i<=n;i++)
      for(int j=0;j<=m;j++)
      {
        if(i==0||j==0)
          dp[i][j]=0;
        else
        {
          if(s1[i-1]==s2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
           else
             dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
      }
      return dp[n][m];

      //printing the lcs....

    int ln=dp[n][m];
    cout<<ln<<"\n";

    int i=n,j=m;
     char s[ln+1];
     s[ln]='\0';
    while(i>0 && j>0)
    {
          if(s1[i-1] == s2[j-1])
          {
            s[ln-1]=s1[i-1];
            ln--;
            i--;j--;
          }
          else
            if(dp[i-1][j]>dp[i][j-1])
               i--;
             else 
              j--;
    }
      cout<<s;
      
}

int spaceopti(int n,int m)
{
   vector<int>prev(m+1);
   vector<int>cur(m+1);

   for(int i=0;i<=n;i++)
      {
        for(int j=0;j<=m;j++)
      {
        if(i==0||j==0)
          cur[j]=0;
        else
        {
          if(s1[i-1]==s2[j-1])
           cur[j]=1+prev[j-1];
           else
            cur[j]=max(prev[j],cur[j-1]);
        }
      }
      prev=cur;
    }
    return cur[m];
}


int main()
{
  cin>>s1>>s2;
  cout<<spaceopti(s1.length(),s2.length());
}
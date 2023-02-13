
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
  
string s;
 
 int dp(int i)
 {
     if(i==s.size())
       return 1;
   int ans=0;
     if(s[i]>='1'&& s[i]<='9')
       ans+=dp(i+1);
     if(i+1 < s.size() && s[i]=='1')
       ans+=dp(i+2);
     if(i+1<s.size() && s[i]=='2' && s[i+1] <='6')
        ans+=dp(i+2);

      return ans;
 }

 int tabdp(int i)
 {
    int n=s.size();
    vector<int>dp(n+1);
    dp[n]=1;
  
    for(int i=n-1;i>=0;i--)
    {
      
      if(s[i]>='1'&& s[i]<='9')
        dp[i]+=dp[i+1];
      if(i+1 < n && s[i]=='1')
        dp[i]+=dp[i+2];
      if(i+1<n && s[i]=='2'&&s[i+2]<='6')
        dp[i]+=dp[i+2];
        
    }
    return dp[0];
 }
 
int main(){
  
  cin>>s;
  cout<<tabdp(0);
}
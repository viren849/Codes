
#include<bits/stdc++.h>
using namespace std;

#define ll              long long 
#define pb              push_back
#define ld              long double
#define F               first
#define S               second 

bool check(string s,int i,int j)
    {
        while(i<j)
            if(s[i++]!=s[j--])return false;
        return true;
    }
string lpsubstring(string s)
{
      //bruteforce
   int n=s.size();
         int ans=INT_MIN;
        int a=0,b=0;
    for(int i=0;i<n;i++)
    {
        
        for(int j=i;j<n;j++)
           {
              if(check(s,i,j))
              {
                 // cout<<j-i+1<<"-"<<s.substr(i,j-i+1)<<" ";
                  if(ans < j-i+1)
                  {
                      ans=max(ans,j-i+1);
                      a=i;
                      b=j;
                  }
              }
            
          }
        
    }
        //cout<<ans<<" ";
        return s.substr(a,b-a+1);
}

//using dp 

 string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,1));
       
        int maxL=1;
        int start=0;

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=i;j--)
            {
                if(s[i]==s[j] && j>0 && i<n-1 && dp[i+1][j-1])
                {
                    dp[i][j]=1;
                    if(maxL < j-i+1)
                    {
                        maxL=j-i+1;
                        start=i;
                    }
                }
                else dp[i][j]=0;
                
            }
        }
        for(auto it : dp)
        {
            for(int i : it)
                cout<<i<<" ";
            cout<<endl;
        }
        cout<<maxL;
        return s.substr(start,maxL);
    }


//Expand around center ....
    class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        
        int maxL=1;
        int start=0;
      
        for(int mid=0;mid<n;mid++)
        {
            for(int x=0; mid-x>=0 && mid+x <n;x++)
            {
                if(s[mid-x] != s[mid+x])
                    break;
                if(maxL < 2*x+1)
                {
                    maxL=2*x+1;
                    start=mid-x;
                }
            }
        }
        
        //for-even.....
        for(int mid=0;mid<n-1;mid++)
        {
            for(int x=1; mid-x+1>=0 && mid+x<n;x++)
            {
                if(s[mid-x+1] != s[mid+x])
                    break;
                if(maxL < 2*x)
                {
                    maxL=2*x;
                    start=mid-x+1;
                }
            }
        }
        
        return s.substr(start,maxL);
    }
};
int main()
{
  string s;
  cin>>s;
  cout<<lpsubstring(s);
  
}
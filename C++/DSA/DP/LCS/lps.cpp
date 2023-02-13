
//LPS
//also LCS(s,reverse(s));

#include<iostream>
#include<vector>
#include<unordered_map>
#include<limits.h>
using namespace std;
using ll=long long;

string s;
int LPS(int i,int j){
   
   if(i>j)
     return 0; 
   if(i==j)
    return 1;
    if(s[i]==s[j])
    {
      return 2+LPS(i+1,j-1);
    }
    
    return max(LPS(i+1,j),LPS(i,j-1));
}


       int tablps(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i+1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];

        //printing LPS

        int i=0,j=n-1;

        int ln=dp[0][n-1];
        int k=i,m=ln-1;
        char ans[ln];
        while(i<=j)
        {
           if(s[i]==s[j])
           {
            ans[k++]=s[i];
            ans[m--]=s[j];
             i++;
             j--;
           }
           else if(dp[i+1][j] > dp[i][j-1])
            i++;
          else
            j--;
        }
        for(char c : ans)cout<<c;
        cout<<endl;
    }



int main()
{
  cin>>s;
  cout<<tablps(0,s.length()-1);
}
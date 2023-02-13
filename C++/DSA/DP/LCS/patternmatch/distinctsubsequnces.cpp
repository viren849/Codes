//count distinct subsequences 
class Solution {
public:
    string a,b;
    int dp[1001][1001];

    //memoization .....
    int func(int n , int m)
    {
        if(m<0)return 1;
        if(n<0)return 0;
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        if(a[n] == b[m])
            return dp[n][m]=func(n-1,m-1)+func(n-1,m);
        else
            return dp[n][m]=func(n-1,m);
    }

    double dp[1001][1001];
    int func(int n , int m)
    {
       
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(j==0) dp[i][j]=1;
                else if(i==0)dp[i][j]=0;
                else
                {
                    if(a[i-1] == b[j-1])
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    else 
                        dp[i][j]=dp[i-1][j];
                }
            }
        return (int)dp[n][m];
        
    }

    int func(int n , int m)
    {
       
        vector<double>prev(m+1),cur(m+1);
        for(int i=0;i<=n;i++)
        { for(int j=0;j<=m;j++)
            {
                if(j==0) cur[j]=1;
                else if(i==0)cur[j]=0;
                else
                {
                    if(a[i-1] == b[j-1])
                        cur[j]=prev[j-1]+prev[j];
                    else 
                       cur[j]=prev[j];
                }
            }
        prev=cur;}
        return (int)cur[m];
        
    }
    int func(int n , int m)
    {
       
        vector<double>cur(m+1);
        for(int i=0;i<=n;i++)
        { 
            for(int j=m;j>=0;j--)
            {
                if(j==0) cur[j]=1;
                else if(i==0)cur[j]=0;
                else
                {
                    if(a[i-1] == b[j-1])
                        cur[j]=cur[j-1]+cur[j];
                    else 
                       cur[j]=cur[j];
                }
            }
      
        }
        return (int)cur[m];
        
    }
    int numDistinct(string s, string t) {
        a=s;
        b=t;
        memset(dp,-1,sizeof(dp));
        return func(s.size()-1 , t.size()-1);
    }
};